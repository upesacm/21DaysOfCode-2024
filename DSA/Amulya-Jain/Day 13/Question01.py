def can_split_string(s, word_dict):
    length = len(s)
    is_segmentable = [False] * (length + 1)
    is_segmentable[0] = True
    
    for i in range(1, length + 1):
        for j in range(i):
            if is_segmentable[j] and s[j:i] in word_dict:
                is_segmentable[i] = True
                break
    
    return "YES" if is_segmentable[length] else "NO"

if __name__ == "__main__":
    test_string = "applepie"
    test_dictionary = {"apple", "pie"}
    print(can_split_string(test_string, test_dictionary))
