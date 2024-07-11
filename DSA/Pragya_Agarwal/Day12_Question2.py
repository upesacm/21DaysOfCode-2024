def num(n):
    if n < 10:
        return n
    add = 0
    while n > 0:
        digit = n%10
        add += digit
        n //=10
    return num(add)

n= 9875
result = num(n)
print(result)
