def is_symmetrical_string(input_string):
    ascii_values = [ord(char) for char in input_string]
    if ascii_values == ascii_values[::-1]:
        return "symmetrical"
    else:
        return "not symmetrical"
user_input = input("Enter a string: ")
result = is_symmetrical_string(user_input)
print(result)
