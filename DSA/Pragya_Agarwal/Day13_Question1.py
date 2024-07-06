def word_break(s,Dict):
    word_set= set(Dict)
    n = len(s)
    dp = [False] * (n + 1)
    dp[0] = True
    
    for i in range(1, n + 1):
        for j in range(i):
            if dp[j] and s[j:i] in word_set:
                dp[i] = True
                break
    return dp[n]
    
string = "applepie"
dictionary = ["apple","pie"]
if word_break(string, dictionary):
   print("Yes")
else:
   print("No")
  
