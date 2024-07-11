def single_digit_sum(number):
  if number < 10:
    return number
  else:
    sum_of_digits = 0
    while number > 0:
      last_digit = number % 10
      sum_of_digits += last_digit
      number //= 10
    return single_digit_sum(sum_of_digits)  # Recursive to handle remaining digits

# Example usage
number = int(input("Enter a number: "))
result = single_digit_sum(number)
print(f"The single digit sum of {number} is: {result}")
