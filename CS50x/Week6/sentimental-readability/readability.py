from cs50 import get_string

letters = 0
words = 0
sentences = 0

text = input("Text: ")
split_text = text.split()
character = "!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~"

# counting letters, words and sentences
# letters
for words in split_text:
    for l in words:
        letters += 1
        if l in character:
            letters -= 1
# words
words = len(split_text)
# sentences
for sentence in text:
    sentences += sentence.count('.') + sentence.count('!') + sentence.count('?')

# calculating averages (letters per 100 words and sentences in text)
L = ((float(letters) / float(words)) * 100)
S = ((float(sentences) / float(words)) * 100)

# calculate reading level via Coleman-liau index / index = 0.0588 * L - 0.296 * S - 15.8
index = ((0.0588 * L) - (0.296 * S))
index = (index - 15.8)
index = round(index)

# printing reading levels
if index < 1:
    print("Before Grade 1")
elif index < 16:
    print(f"Grade", index)
else:
    print("Grade Grade 16+")
