books = []

 #Add three books to the shelf
for i in range(3):
    book = dict()
    book["titel"] = input("Titel: ").strip().capitalize() #making Key with value titel / user input
    print(book["titel"], end=" ")

    print()
    book["author"] = input("Author: ").strip().capitalize()

    books.append(book)


for book in books:
    print(book["titel"], end=" ")

print()