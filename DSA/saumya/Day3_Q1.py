#QUES1

import string

sentence = input("Enter a sentence: ")

check_pangram = all(char in sentence.lower() for char in string.ascii_lowercase)

if check_pangram:
  print("Complete")
else:
  print("Incomplete")

#Test case 1
#Enter a sentence: The quick brown fox jumps over the lazy dog
#Complete

#Test case 2
#Enter a sentence: This is a book
#Incomplete

