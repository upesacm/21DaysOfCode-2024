def sum_digits_until_single_digit(number):
    if number < 10:
        return number
    else:
        digit_sum = sum(int(digit) for digit in str(number))
        return sum_digits_until_single_digit(digit_sum)
number = 9875
print(sum_digits_until_single_digit(number))  
