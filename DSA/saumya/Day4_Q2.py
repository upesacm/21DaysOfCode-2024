def rearrange(string):
  char_counts = {}
  for char in string:
    char_counts[char] = char_counts.get(char, 0) + 1
  max_freq = max(char_counts.values())
  min_freq = min(char_counts.values())
  # Checking if removing at most one character can give equal frequencies
  if max_freq - min_freq <= 1:
    return "valid"
  else:
    return "invalid"

# Test case 1
string = "aabbcc"
result = rearrange(string)
print("Output : ",result)  # Output: "valid"

#Tese case 2
string = "aaabb"
result = rearrange(string)
print("Output : ",result)  # Output: "valid"

#Test case 3
string="aaaabb"
result= rearrange(string)
print("Output : ",result) #Output: "invalid"
