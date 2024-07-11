def is_balanced(string: str) -> str:
    stack = []
    bracket_map = {')': '(', '}': '{', ']': '['}

    for char in string:
        if char in bracket_map.values():
            stack.append(char)
        elif char in bracket_map.keys():
            if stack == [] or bracket_map[char] != stack.pop():
                return "NO"
        else:
            continue
    return "YES" if not stack else "NO"
string = "{[()]}"
print(is_balanced(string))
