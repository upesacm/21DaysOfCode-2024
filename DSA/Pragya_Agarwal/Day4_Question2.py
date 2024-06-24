string = "aaabbbcc"
freq = {}
for char in string:
    if char in freq:
        freq[char] += 1
    else:
        freq[char] = 1

freq_count = {}
for count in freq.values():
    if count in freq_count:
        freq_count[count] += 1
    else:
        freq_count[count] = 1

if len(freq_count) == 1:
    print("valid")
elif len(freq_count) == 2:
    keys = list(freq_count.keys())
    key1, key2 = keys[0], keys[1]
    count1, count2 = freq_count[key1], freq_count[key2]
    
    if key1 > key2:
        key1, key2 = key2, key1
    
    if (key2 == key1 + 1 and count2 == 1) or (key1 == 1 and count1 == 1):
        print("invalid")
    else:
        print("valid")
else:
    print("invalid")
