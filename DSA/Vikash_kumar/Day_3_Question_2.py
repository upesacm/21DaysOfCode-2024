#Day3-Question2-
def is_symmetrical(string):
    ascii_values = [ord(char) for char in string]
    
    if ascii_values == ascii_values[::-1]:
        return "symmetrical"
    else:
        return "not symmetrical"

string = input("Enter the string : ")
print(is_symmetrical(string)) 
