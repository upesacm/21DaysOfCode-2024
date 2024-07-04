def check_palindrome(number):
  original_number = number
  reversed_number = 0
  while number > 0:
    # Extract last digit and add it to the reversed number
    last_digit = number % 10
    reversed_number = reversed_number * 10 + last_digit
    # Remove the last digit from the original number
    number //= 10
  if original_number == reversed_number :
      return "YES"
  else:
      return "NO"

# TEST CASE
number = 121
result = check_palindrome(number)
print(result)  # output: YES
