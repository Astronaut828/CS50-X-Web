import csv
from cs50 import SQL

# Connect to database
db = SQL("sqlite:///roster.db")

# Initialize variable for house IDs
house_id = 0

# Open students.csv and insert data into database
with open("students.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:

        # Insert new house into houses table
        db.execute(INSERT INTO houses (house, head) VALUES (row["house"], row["head"]));



