from cs50 import get_float

# asking fot user input
while True:
    change = get_float("Change owed: ")
    if change >= 0:
        break

change_cents = round(change * 100)

# initialize coin counter
coins = 0

# calculate coins
while change_cents > 0:
    if change_cents >= 25:
        coins += 1
        change_cents -= 25
    elif change_cents >= 10:
        coins += 1
        change_cents -= 10
    elif change_cents >= 5:
        coins += 1
        change_cents -= 5
    else:
        coins += 1
        change_cents -= 1

# print coin ammount
print(coins)

