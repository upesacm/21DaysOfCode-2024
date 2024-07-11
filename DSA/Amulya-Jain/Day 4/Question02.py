def Rearr_Freq_same(s):
    freq = {}
    for char in s:
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
        return "valid"
    elif len(freq_count) == 2:
        keys = list(freq_count.keys())
        if (keys[0] == 1 and freq_count[keys[0]] == 1) or (keys[1] == 1 and freq_count[keys[1]] == 1):
            return "valid"
        elif abs(keys[0] - keys[1]) == 1 and (freq_count[keys[0]] == 1 or freq_count[keys[1]] == 1):
            return "valid"
        else:
            return "invalid"
    else:
        return "invalid"

def main ():
  string = "aabbcc"
  print(Rearr_Freq_same(string)) 

if __name__ == "__main__":
    main()
