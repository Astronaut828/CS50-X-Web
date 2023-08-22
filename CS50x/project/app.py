from flask import Flask, flash, redirect, render_template, request
import sqlite3

# Configure application
app = Flask(__name__)
app.config['SECRET_KEY'] = 'Monkey'

@app.route('/')
def layout():
    return render_template("index.html")

@app.route('/starthere')
def starthere():
    return render_template("starthere.html")

@app.route('/spotlight')
def spotlight():
    return render_template("spotlight.html")

@app.route('/gallery')
def blog():
    return render_template("gallery.html")

@app.route('/contact')
def contact():
    return render_template("contact.html")

@app.route('/index', methods=["GET", "POST"])
def signup():
    if request.method == "POST":
        name = request.form.get("name")
        email = request.form.get("email")

        name = name.lower()
        email = email.lower()

        # Establish a connection to the SQLite database
        with sqlite3.connect('newsletter.db') as conn:
            # Create a cursor object
            db = conn.cursor()

            # Check for existing email in subscribers table
            db.execute("SELECT COUNT(*) FROM subscribers WHERE email = ?", (email,))
            double = db.fetchone()[0]

            if double > 0:
                print("Error: Email already exists.")

            else:
                # Prepare the SQL statement with placeholders
                sql = "INSERT INTO subscribers (name, email) VALUES (?, ?)"

                # Execute the SQL statement with the parameters
                db.execute(sql, (name, email))

                # Commit the transaction
                conn.commit()

            # refrence for delete

            # .open filename.db
            # DELETE FROM subscribers WHERE id =1;

        return redirect("/")
    else:
        return render_template("index.html")


