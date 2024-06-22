def birthday(candy, day, month):
    count = 0
    for i in range(len(candy) - month + 1):
        if sum(candy[i:i+month]) == day:
            count += 1
    return count

candy = [4, 5 ,4, 1, 2, 4, 3]
day = 9
month = 3
print(birthday(candy, day, month)) 