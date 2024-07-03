def sum_digits(n):

    if n < 10:
        return n
    else:
        return sum_digits(sum(int(digit) for digit in str(n)))
    
print(sum_digits(9875)) 

