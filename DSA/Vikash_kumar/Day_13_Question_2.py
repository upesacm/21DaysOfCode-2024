#Day13-Question2-
def is_palindrome_recursive(s, start, end):
    if start >= end:
        return True
    if s[start] != s[end]:
        return False

    return is_palindrome_recursive(s, start + 1, end - 1)

def is_palindrome(number):
    s = str(number)

    if is_palindrome_recursive(s, 0, len(s) - 1):
        return "YES"
    else:
        return "NO"

number = int(input("Enter the number: "))
print(is_palindrome(number)) 
