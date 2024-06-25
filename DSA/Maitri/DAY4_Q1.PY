def is_palindrome(s):
    return s == s[::-1]

def palindromic_substrings(string, length):
    if length > len(string):
        return 0

    for i in range(len(string) - length + 1):
        substring = string[i:i + length]
        if is_palindrome(substring):
            palindromic_substrings.add(substring)

    return len(palindromic_substrings)

# Taking user inputs
string = input("Enter the string: ")
length = int(input("Enter the length of substrings: "))

result = palindromic_substrings(string, length)

print(result)
