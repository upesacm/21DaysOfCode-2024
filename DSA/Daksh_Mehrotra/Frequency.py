from collections import Counter
def is_valid_string(s):
    char_count = Counter(s)
    freq_count = Counter(char_count.values())
    if len(freq_count) == 1:
        return "valid"
    elif len(freq_count) == 2:
        freq1, freq2 = freq_count.keys()
        if (freq_count[freq1] == 1 and (freq1 - 1 == 0 or freq1 - 1 == freq2)) or \
           (freq_count[freq2] == 1 and (freq2 - 1 == 0 or freq2 - 1 == freq1)):
            return "valid"
    return "invalid"
string = input("Enter a string: ")
print(is_valid_string(string))
