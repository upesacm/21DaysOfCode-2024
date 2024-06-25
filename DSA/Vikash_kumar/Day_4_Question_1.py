#Day4-Question1-
def count_distinct_palindromic_substrings(s, length):
    def is_palindrome(sub):
        return sub == sub[::-1]
    
    palindromic_substrings = set()
    
    for i in range(len(s) - length + 1):
        substring = s[i:i + length]
        if is_palindrome(substring):
            palindromic_substrings.add(substring)
    
    return len(palindromic_substrings)

string = input("Enter the string : ")
length = int(input("Enter the length of the substrings : "))
print(count_distinct_palindromic_substrings(string, length)) 
