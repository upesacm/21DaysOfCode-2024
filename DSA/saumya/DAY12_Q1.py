def fibonacci(n):
  if n == 0:
    return 0
  elif n == 1:
    return 1
  else:
    return fibonacci(n-1) + fibonacci(n-2)

# TEST CASE-1
n = 5
result = fibonacci(n)
print(f"The {n}th Fibonacci number is: {result}") #output: 5

#TEST CASE-2
n=3
result=fibonacci(n)
print(f"The {n}th Fibonacci number is: {result}") #output: 2
