def is_balanced(s: str):
    stack = []
    bracket_map = {")": "(", "}": "{", "]": "["}

    for char in s:
        if char in bracket_map.values():
            stack.append(char)
        elif char in bracket_map:
            if not stack or stack.pop() != bracket_map[char]:
                return "NO"

    return "YES" if not stack else "NO"
print(is_balanced("{[()]}"))  

