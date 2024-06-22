def count_ways(candy, day, month):
    count = 0
    n = len(candy)
    
    for i in range(n - month + 1):
        segment = candy[i:i + month]
        if sum(segment) == day:
            count += 1
    
    return count

candy = list(map(int, input("Enter the elements of the candy array separated by spaces: ").split()))
day = int(input("Enter Raju's birth day: "))
month = int(input("Enter Raju's birth month: "))


result = count_ways(candy, day, month)
print(f"The number of valid ways to divide the bar is: {result}")
