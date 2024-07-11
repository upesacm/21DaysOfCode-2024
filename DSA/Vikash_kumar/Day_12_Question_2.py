#Day12-Question2-
def sum_digits(number):
    if number < 10:
        return number
    else:
        # Sum the digits of the number
        digit_sum = sum(int(digit) for digit in str(number))
        # Recursively call the function with the new sum
        return sum_digits(digit_sum)

n = int(input("Enter a number: ")
print(f"The single digit result for {n} is {sum_digits(n)}")
