def isPalindrome(num):
    num_str = str(num)
    return checkPalindrome(num_str, 0, len(num_str) - 1)
def checkPalindrome(s, left, right):
    if left >= right:
        return True
    if s[left] != s[right]:
        return False
    return checkPalindrome(s, left + 1, right -1)
def isPalindromeNumber(num):
    return "YES" if isPalindrome(num) else "NO"
number = 121
print(isPalindromeNumber(number)) 
