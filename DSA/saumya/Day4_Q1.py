def count_subsets_of_palindromes(string, length):
  
  result = set()
  for i in range(len(string) - length + 1):
    substring = string[i:i + length]
    if substring == substring[::-1]:
      result.add(substring)
  return len(result)

# Test case
string = "ababa"
length = 3
res = count_subsets_of_palindromes(string, length)
print(res)  
# Output: 2 (both "aba" and "bab" are considered as distinct substrings of palindrom)
