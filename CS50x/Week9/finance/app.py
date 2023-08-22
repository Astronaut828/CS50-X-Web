import os
import requests
from cs50 import SQL
from datetime import datetime
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # User ID
    user = session.get("user_id")

    # Checking stocks in Portfolio
    stocks = db.execute("SELECT symbol FROM stocks WHERE user_id = ? GROUP BY(symbol)", (user))

    # Retrieve shares the user owns for each stock symbol
    shares = db.execute("SELECT shares, symbol FROM user_shares WHERE user_id = ?", (user))

    # Create a new list of dictionaries to store each stock
    stock_list = []

    # Loop through the stocks and create a dictionary for each stock
    for stock in stocks:
        stock_symbol = stock["symbol"]

        # Find the corresponding shares for the stock symbol
        for share in shares:
            if share["symbol"] == stock_symbol:
                stock_shares = share["shares"]
                break
        else:
            stock_shares = 0

        # API call for each stock symbol
        quote = lookup(stock_symbol)

        if quote is not None:
            stock_dict = {
                "symbol": stock_symbol,
                "name": quote["name"],
                "price": quote["price"],
                "shares": stock_shares,
                "total_value": quote["price"] * stock_shares,  # Calculation of total value
            }
            stock_list.append(stock_dict)

    # get value of all stocks in holding
    total_value_sum = 0
    for stock in stock_list:
        total_value_sum += stock["total_value"]

    # Current user cash funds
    user_founds = db.execute("SELECT cash FROM users WHERE id = ?", (user))
    user_founds = user_founds[0]["cash"]

    # Account value calculation
    account_total = total_value_sum + user_founds

    return render_template("index.html", stock_list=stock_list, user_founds=user_founds, account_total=account_total, shares=shares)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        # Error id user does not input a symbol
        if not request.form.get("symbol"):
            return apology("MISSING SYMBOL", 400)

        # Setting up call with correct symbol
        elif request.form.get("symbol"):
            symbol = request.form.get("symbol")
            # Api call / lookup
            quote = lookup(symbol)
            # Error code if symbol is invalid
            if quote == None:
                return apology("INVALID SYMBOL", 400)

        # Error for empty shares value
        if not request.form.get("shares"):
            return apology("MISSING SHARES", 400)

        # Number of shares requested
        shares = request.form.get("shares")

        try:
            shares = int(shares)  # Try converting to an integer
            if shares <= 0:
                raise ValueError  # Raise an error if shares is not positive
        except (ValueError, TypeError):
            return apology("INVALID INPUT", 400)

        # api call for symbol requested
        if shares > 0:

            buy_data = lookup(symbol)

            name = buy_data['name']
            sym = buy_data['symbol']

            price = "{:.2f}".format(buy_data['price'])
            price = float(price)

            total = price * shares
            total = "{:.2f}".format(total)
            total = float(total)

            # Timestamp
            date_time = datetime.now()
            time = date_time.strftime("%d/%m/%Y %H:%M:%S")

            # User ID
            user = session.get("user_id")

            # Type of transaction
            buy = "buy"

            # User founds
            amount = db.execute("SELECT cash FROM users WHERE id = ?", (user))
            founds = amount[0]['cash']

            # checking if user already holds shares, if yes adding new ones
            current_shares = db.execute("SELECT symbol, shares FROM user_shares WHERE user_id = ? GROUP BY(symbol)", (user))

            if founds >= total:

                # Updating cash holdings for user
                new_founds = founds - total
                db.execute("UPDATE users SET cash=(?) WHERE id=(?)", (new_founds), (user))

                # Inserting User / buy info into database, safe against injections
                db.execute("INSERT INTO stocks (user_id, symbol, name, shares, price, total, trans_type) VALUES(?, ?, ?, ?, ?, ?, ?)",
                           (user), (sym), (name), (shares), (price), (total), (buy))

                # Updating user_shares table in database
                for item in current_shares:
                    if item['symbol'] == sym:
                        share_holding = item['shares']
                        new_share_holding = share_holding + shares
                        break
                else:
                    new_share_holding = shares

                trans_type = "purchase "

                # Inserting and Updating new purchase in databank
                db.execute("INSERT INTO  user_shares (user_id, symbol, shares) VALUES(?,?,?)",
                           (user), (sym), (new_share_holding))

                db.execute("UPDATE user_shares SET shares = ? WHERE symbol = ? AND user_id = ?", (new_share_holding), (sym), (user))

                flash(f'Bought {shares} shares of {sym} successfully!')
                return redirect("/")

            else:
                return apology("CAN'T AFFORD", 400)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user = session.get("user_id")
    history = db.execute("SELECT * FROM stocks WHERE user_id = ?", (user))

    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":

        # Error id user does not input a symbol
        if not request.form.get("symbol"):
            return apology("MISSING SYMBOL", 400)

        # Setting up call with correct symbol
        elif request.form.get("symbol"):
            symbol = request.form.get("symbol")
            # Api call / lookup
            quote = lookup(symbol)
            # Error code if symbol is invalid
            if quote == None:
                return apology("INVALID SYMBOL", 400)

            # Setting up call with correct symbol
            elif request.form.get("symbol"):
                symbol = request.form.get("symbol")

                # Api call / lookup
                quote = lookup(symbol)

                name = quote['name']
                sym = quote['symbol']
                price = quote['price']

                # Return of values after successful call
                return render_template("quoted.html", name=name, symbol=sym, price=price)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])  # works // finished for now (add case insensitive / Name)
def register():
    """Register user"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("MUST PROVIDE USERNAME", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("MUST PROVIDE PASSWORD", 400)

        # Ensure password was submitted
        elif not request.form.get("confirmation"):
            return apology("PASSWORD DOES NOT MATCH", 400)

        # Ensure passwords submitted are matching
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("PASSWORD DOES NOT MATCH", 400)

        user = request.form.get("username")
        user = user.lower()

        # Checking for existing user names
        check = db.execute("SELECT COUNT(*) FROM users WHERE username = ?", (user))
        double = check[0]['COUNT(*)']
        if double > 0:
            return apology("USERNAME ALREADY EXISTS", 400)

        password = request.form.get("password")

        # Hashing the password
        hash_word = generate_password_hash(password)

        # Inserting User info into database, safe against injections
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", user, hash_word)

        # Redirect user to home page
        return render_template("login.html")

    else:
        return render_template("/register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # Ensure username was submitted
    user = session.get("user_id")
    # Checking stocks in Portfolio
    stocks = db.execute("SELECT symbol FROM stocks WHERE user_id = ? GROUP BY(symbol)", (user))

    if request.method == "POST":

        # Error messages for missing input
        if not request.form.get("symbol"):
            return apology("MISSING SYMBOL", 400)

        if not request.form.get("shares"):
            return apology("MISSING SHARES", 400)

        # Getting user input
        if request.form.get("symbol"):
            symbol = request.form.get("symbol")

        if request.form.get("shares"):
            shares = request.form.get("shares")
            shares = int(shares)

        # Retrieve shares the user owns for each stock symbol
        owned_shares = db.execute("SELECT SUM(shares), symbol FROM stocks WHERE user_id = ? GROUP BY(symbol)", (user))

        # Checking if Symbol is within owned shares and if user ownes enough shares to complete sell
        if symbol in [stock['symbol'] for stock in stocks]:
            for owned in owned_shares:
                if symbol == owned['symbol']:
                    if shares > owned['SUM(shares)']:
                        return apology("TOO MANY SHARES", 400)
        else:
            return apology("MISSING SYMBOL", 400)

        # Api call / lookup symbol and get current price
        stock_price = lookup(symbol)

        name = stock_price['name']

        price = stock_price['price']
        sell_value = price * shares

        # Updating cash holdings for user
        amount = db.execute("SELECT cash FROM users WHERE id = ?", (user))
        amount = amount[0]['cash']
        new_founds = sell_value + amount
        db.execute("UPDATE users SET cash=(?) WHERE id=(?)", (new_founds), (user))

        # Updating share holdings for user
        share_holding = owned_shares = db.execute(
            "SELECT SUM(shares), symbol FROM stocks WHERE user_id = ? GROUP BY(symbol)", (user))

        # transaction type
        trans_type = "sale"

        for stock in share_holding:
            if stock['symbol'] == symbol:
                stock['SUM(shares)'] -= shares
                updated = stock['SUM(shares)']

                db.execute("UPDATE user_shares SET shares=(?) WHERE user_id =(?) AND symbol=(?) ", (updated), (user), (symbol))

                # Inserting User / buy info into database, safe against injections
                db.execute("INSERT INTO stocks (user_id, symbol, name, shares, price, total, trans_type) VALUES(?, ?, ?, ?, ?, ?, ?)",
                           (user), (symbol), (name), (shares), (price), (sell_value), (trans_type))

        flash('Sold!')
        return redirect("/")

    else:
        return render_template("sell.html", stocks=stocks)


@app.route("/dollar", methods=["GET", "POST"])
@login_required
def dollar():
    """Add cash to the users account"""
    user = session.get("user_id")

    if request.method == "POST":

        new_funds = request.form.get("amount")

        # Validate the input and allow only decimal points and commas
        valid_chars = "0123456789."
        cleaned_input = "".join(char for char in new_funds if char in valid_chars)

        try:
            new_funds = float(cleaned_input)  # Try converting to a float
            if new_funds <= 0 or new_funds > 1000000:
                raise ValueError  # Raise an error if new_funds is not positive
        except (ValueError, TypeError):
            return apology("INVALID INPUT / INPUT DOLLAR AMOUNT", 400)

        # Get current cash amount of user
        amount = db.execute("SELECT cash FROM users WHERE id = ?", (user))
        # Update balance
        new_balance = amount[0]['cash'] + new_funds
        # Update databank with new balance
        db.execute("UPDATE users SET cash=(?) WHERE id=(?)", (new_balance), (user))

        return redirect("/")

    else:
        return render_template("dollar.html")