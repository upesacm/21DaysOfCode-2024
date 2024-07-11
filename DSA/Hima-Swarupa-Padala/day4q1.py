def count_palindromic_substrings(s, length):
    def is_palindrome(substring):
        return substring == substring[::-1]

    substrings = set()
    for i in range(len(s) - length + 1):
        substring = s[i:i + length]
        if is_palindrome(substring):
            substrings.add(substring)

    return len(substrings)

string = "ababa"
length = 3
print(count_palindromic_substrings(string, length)) 