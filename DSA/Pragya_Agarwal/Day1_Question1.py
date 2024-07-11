candy = [2, 2, 1, 3, 2]
birth_day = 4
birth_month = 2

count = 0
n = len(candy)

for i in range(0, n - birth_month + 1):
    sum_of_segment = 0
    for j in range(0,birth_month):
        sum_of_segment += candy[i + j]
    
    if sum_of_segment == birth_day:
        count += 1

print("The number of valid ways to divide the bar:",count) 
