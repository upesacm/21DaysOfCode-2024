string = "acxz"
ascii_value = []

for char in string.lower():
    if 'a' <= char <= 'z':
        character = chr(ord('a') + (ord('z') - ord(char)))
    else:
        character = char
    ascii_value.append(character)

new_string = ''.join(ascii_value)

reversed_string = new_string[::-1]

if reversed_string == string:
    print("symmetrical")
else:
    print("not symmetrical")

print("Reversed transformed string:", reversed_string)
