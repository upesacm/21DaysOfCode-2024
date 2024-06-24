def is_symmetrical(string):
    mirror_map = str.maketrans('abcdefghijklmnopqrstuvwxyz', 'zyxwvutsrqponmlkjihgfedcba')
    reversed_string = string.translate(mirror_map)[::-1]    
    if string == reversed_string:
        return "symmetrical"
    else:
        return "not symmetrical"
print(is_symmetrical("bcxy"))  
print(is_symmetrical("abcd"))  
