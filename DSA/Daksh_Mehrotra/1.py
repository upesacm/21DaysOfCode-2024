def birthday_chocolate(candy, day, month):
    n = len(candy)
    count = 0
    current_sum = sum(candy[:month])
    if current_sum == day:
        count += 1
    for i in range(month, n):
        current_sum = current_sum - candy[i - month] + candy[i]
        if current_sum == day:
            count += 1
    return count
candy = [2, 2, 1, 3, 2]
day = 4
month = 2
result = birthday_chocolate(candy, day, month)
print(result)  
