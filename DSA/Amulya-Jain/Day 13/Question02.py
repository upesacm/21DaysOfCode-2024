is_palindrome_recursive = lambda s, left, right: (
    True if left >= right else
    False if s[left] != s[right] else
    is_palindrome_recursive(s, left + 1, right - 1)
)

is_palindrome = lambda number: (
    "YES" if is_palindrome_recursive(str(number), 0, len(str(number)) - 1) else "NO"
)

if __name__ == "__main__":
    number = 121
    print(is_palindrome(number))
