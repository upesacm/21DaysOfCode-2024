def seq_dict_words(string, dictionary):

    n = len(string)
 
    dp = [False] * (n + 1)
    dp[0] = True 

    for i in range(1, n + 1):
        for j in range(i):
            
            if dp[j] and string[j:i] in dictionary:
                dp[i] = True
                break

    if dp[n]:
        return "YES"
    
    else:
        return "NO"

string = "applepie"
dictionary = {"apple", "pie"}
print(seq_dict_words(string, dictionary))  
