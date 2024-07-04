#Day12-Question1-
def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

n = int(input("Enter the position of the Fibonacci number: "))
print(f"Fibonacci number at position {n} is {fibonacci(n)}")
