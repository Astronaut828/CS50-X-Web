text = "In the great green room"
words = text.split()
print()

#round 1
print("Round 1")
for word in words:
    print(word, end=" ") #to print in one line , end=" "
print()
print()

#round 2
print("Round 2")
for word in words:
    for c in word:
        print(c, end=" ")
print()
print()

#round 3
print("Round 3")
for word in words:
    if "g" in word: # every word with g in it
        print(word)
print()

#round 4
print("Round 4") # slicing
for word in words [2:]: #prints every element after index [2] / or the slice between [2:4] incl : exclusive
    print(word)
print()

#round 5
print("Round 5")
for _ in words: # just looping that many times
    print("Goodnight Moon")
print()


#round 6
print("Round 6")
