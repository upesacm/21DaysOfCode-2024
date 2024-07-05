#Day13-Question1-
def word_break(s, word_dict):
    word_set = set(word_dict)
  
    dp = [False] * (len(s) + 1)
    dp[0] = True  
  
    for i in range(1, len(s) + 1):
        for j in range(i):
            if dp[j] and s[j:i] in word_set:
                dp[i] = True
                break
    
    return "YES" if dp[len(s)] else "NO"

string = input("Enter the string: ")
dictionary = input("Enter the dictionary words separated by space: ").split()

result = word_break(string, dictionary)
print(result)
