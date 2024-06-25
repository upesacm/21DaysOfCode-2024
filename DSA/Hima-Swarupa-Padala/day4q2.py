def can_rearrange(string):
    
    char_count = {}
    for char in string:
        char_count[char] = char_count.get(char, 0) + 1
    freq_set = set(char_count.values())
    if len(freq_set) == 1:
        return "valid"
    elif len(freq_set) == 2 and 1 in freq_set:
        return "valid"
    else:
        return "invalid"
    
input_string = "aabbcc"
print(can_rearrange(input_string)) 
