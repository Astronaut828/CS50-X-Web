#bank

text = input("Greeting: ").strip().lower()
greeting = text.split()
correct = greeting[0].strip(',''.')

if correct == "hello":
    print("$0")

elif correct[0] == "h":
    print("$20")

elif correct[0] != "h":
    print("$100")