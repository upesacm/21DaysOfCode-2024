string = "{[()]}"
stack = []
for char in string:
    if char in "{[(":
        stack.append(char)
    elif char in ")]}":
        if not stack:
            print("No")
            break
        top = stack.pop()
        if (char == ')' and top != '(') or \
           (char == '}' and top != '{') or \
           (char == ']' and top != '['):
            print("No")
            break
else:
    if not stack:
        print("Yes")
    else:
        print("No")
