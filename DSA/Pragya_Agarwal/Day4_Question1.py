string = "ababa"
length = 3
n = len(string)
palindromes = set()

for i in range(n - length + 1):
    substring = string[i:i+length]
    if substring == substring[::-1]:
        palindromes.add(substring)
        
result = len(palindromes)
print("Number of distinct palindromic substrings of length",length,":",result)
