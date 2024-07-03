def palindrome(num,temp=None,rev=None):
    if rev is None:
        rev = 0
    if temp == 0:
        return num == rev
    if temp is None:
        temp = num
    digit = temp % 10
    rev = rev * 10 + digit
    return palindrome(num, temp // 10, rev)

num = 121
if palindrome(num):
    print(num,'is palindrome')
else:
    print(num,'is not a palindrome')
