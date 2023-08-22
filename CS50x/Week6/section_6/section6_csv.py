#CSV module
#csv = comma seperated files

import csv / full box of functions

# getting only some of its methods
# from csv import DictReader


csv.DictReader() # with having to add the csv. you can avoid collusions of names
csv.reader()


# to open all you need to do is file = open("books.csv)
# opening a file and closing it after a action has been peformed
with open("Filename.csv") as file:
    text = file.read()
    print(text) #will print the values in FILENAME

# once we undent the file will be closed
with open("books.csv") as file:
    file_reader = csv.Dictreader(file) #special reader / csv.Dictreader() // wont print first row / knows its the Key names
    for book in file_reader:
        books.append(book)

for book in books:
    print(book["titel"]) # prints out indiviual titels from dictionaries

