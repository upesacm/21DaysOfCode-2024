def can_rearrange_to_same_frequency(s):
    from collections import Counter

    char_count = Counter(s)
    freq_count = Counter(char_count.values())

    if len(freq_count) == 1:
        return "Valid"
    elif len(freq_count) == 2:
        freq1, freq2 = freq_count.keys()
        count1, count2 = freq_count.values()

        if(count1 == 1 and (freq1 - 1 == freq2 or freq1 == 1)) or (count2 == 1 and (freq2 - 1 == freq1 or freq2 == 1)):
            return "valid"
    return "Invalid"

string = input("Enter the string : ")
print(can_rearrange_to_same_frequency(string))
