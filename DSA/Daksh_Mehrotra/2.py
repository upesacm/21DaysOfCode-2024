def is_symmetrical(string):
    if string == string[::-1]:
        return "symmetrical"
    else:
        return "not symmetrical"
string = input("Enter a string: ")
print(is_symmetrical(string))
