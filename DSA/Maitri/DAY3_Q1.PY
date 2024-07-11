
string = input("Enter the string: ")
string = string.lower()
letters_found = set()
for char in string:
    if char.isalpha():
        letters_found.add(char)

if len(letters_found) == 26:
    print("complete")
else:
    print("incomplete")
