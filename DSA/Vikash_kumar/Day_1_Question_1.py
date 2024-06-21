def birthday_candy(candy, day, month):
    count = 0
    candy_sum = 0
    candy_size = 0
    
    for i in range(len(candy)):
        candy_sum += int(candy[i])
        candy_size += 1
        
        if candy_size > month:
            candy_sum -= int(candy[i - month])
            candy_size -= 1
        
        if candy_size == month and candy_sum == day:
            count += 1
    return count

candy = []
candy = input("Enter the number written on squares of candy with a space : ").split(" ")
day = int(input("Enter the Raju's birth day : "))
month = int(input("Enter the Raju's birth month : "))
print(birthday_candy(candy, day, month)) 
