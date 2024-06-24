def is_ascii_symmetrical(string):
    ascii_values = [ord(char) for char in string]

    if ascii_values == ascii_values[::-1]:
        return 'Symmetrical'
    else:
        return "Not Symmetrical"
    
string = input("Enter the String = ")
print(is_ascii_symmetrical(string))