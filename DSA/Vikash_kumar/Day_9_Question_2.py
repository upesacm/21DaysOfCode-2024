#Day9-Question2-
def is_balanced(brackets):
    stack = []
    bracket_map = {')': '(', '}': '{', ']': '['}

    for char in brackets:
        if char in bracket_map.values():
            stack.append(char)
        elif char in bracket_map.keys():
            if stack == [] or bracket_map[char] != stack.pop():
                return "NO"
        else:
            continue

    return "YES" if stack == [] else "NO"

string = input("Enter the string : ")
print(is_balanced(string))
