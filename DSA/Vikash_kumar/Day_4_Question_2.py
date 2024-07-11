#Day4-Question2-
from collections import Counter

def can_be_rearranged_to_equal_frequency(s):
    # Count the frequency of each character
    freq = Counter(s)
    
    # Count the frequencies of the frequencies
    freq_of_freq = Counter(freq.values())
    
    # If there's only one frequency or all characters already have the same frequency
    if len(freq_of_freq) == 1:
        return "valid"
    
    if len(freq_of_freq) == 2:
        # Get the two frequencies
        keys = list(freq_of_freq.keys())
        key1, key2 = keys[0], keys[1]
        
        # Check the cases:
        # 1. One frequency appears exactly once and is one more than the other frequency
        # 2. One frequency is 1 and appears exactly once (removing one character)
        if (freq_of_freq[key1] == 1 and (key1 == 1 or key1 - 1 == key2)) or \
           (freq_of_freq[key2] == 1 and (key2 == 1 or key2 - 1 == key1)):
            return "valid"
    
    return "invalid"

string = input("Enter the string : ")
print(can_be_rearranged_to_equal_frequency(string))  # Output: valid
