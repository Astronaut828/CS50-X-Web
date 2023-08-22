# Get user input / positive int between 0-8, prompting until true
while True:
    try:
        high = int(input("Height: "))
    # Checking for integer value from user
    except ValueError:
        print("Sorry, invalid.")
        continue
    # Input value between 0 and 8 incl.
    if high >= 1:
        if high <= 8:
            break

high = int(high)
space = " "
block = 1
wide = high
# Printing Blocks
for row in range(high):
    wide -= 1
    print(f"{space * wide}{'#' * block}", end="")
    block += 1
    print()

