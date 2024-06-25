from collections import Counter

def is_valid_string(string):
    
    freq = Counter(string)
    freq = Counter(freq.values())
    if len(freq) == 1:
        return "valid"
    elif len(freq) == 2:
        keys = list(freq.keys())
        if (freq[keys[0]] == 1 and (keys[0] - 1 == keys[1] or keys[0] == 1)) or (freq[keys[1]] == 1 and (keys[1] - 1 == keys[0] or keys[1] == 1)):
            return "valid"
    
    return "invalid"

string = input("Enter the string: ")


result = is_valid_string(string)

print(result)
