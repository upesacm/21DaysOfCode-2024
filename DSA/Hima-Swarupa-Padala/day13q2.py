def is_palindrome(n, temp=0):
    if n == 0:
        return temp
    else:
        digit = n % 10
        temp = (temp * 10) + digit
        return is_palindrome(n // 10, temp)

def check_palindrome(n):

    if n == is_palindrome(n):
        return "YES"
    
    else:
        return "NO"
    
print(check_palindrome(121))  
