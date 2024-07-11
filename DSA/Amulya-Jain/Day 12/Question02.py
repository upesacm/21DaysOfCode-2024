sum_digits = lambda x: x if x < 10 else sum_digits(sum(int(digit) for digit in str(x)))

def main():
    number = 9875
    result = sum_digits(number)
    print(f"The single digit sum of {number} is: {result}")

if __name__ == "__main__":
    main():
