def count_distinct_palindromic_substrings(s, length):
    palindromic_substrings = set()

    for i in range(len(s) - length + 1):
        substring = s[i:i+length]

        if substring == substring[::-1]:
            palindromic_substrings.add(substring)
    return len(palindromic_substrings)

string = input("Enter the string: ")
length = int(input("Enter the length of substrings: "))

print(f"The number of distinct palindromic substrings of length {length} is: {count_distinct_palindromic_substrings(string, length)}")
