# importing ger_string from the cs50 library
from cs50 import get_string

# taking in the input of text
text = get_string("Text: ")

# initializing the number of letters, words and sentences to 0
letters = 0
words = 0
sentences = 0

# iterating over all the characters in the text
for characters in text:

    # if the character is an alphabet
    if characters.isalpha():
        letters += 1

    # if there is a space in the text
    if characters == ' ':
        words += 1

    # if there is a punctuation in the text
    if characters == '.' or characters == '?' or characters == '!':
        sentences += 1

# increasing words by 1 because the first space separates 2 words
words += 1

# calculating the index
L = (float)(100 * letters) / words
S = (float)(100 * sentences) / words

index = (0.0588 * L) - (0.296 * S) - 15.8
index = round(index)

# displaying the result
if index < 1:
    print("Before Grade 1")

elif index >= 16:
    print("Grade 16+")

else:
    print(f"Grade {index}")
