chocolate = [1, 2, 1, 3, 2]
d = 3
m = 2

def count_ways_to_divide(chocolate, d, m):
    if len(chocolate) < m:
        return 0
    
    count = 0
    current_sum = sum(chocolate[:m])
    
    if current_sum == d:
        count += 1
        
    for i in range(len(chocolate) - m):
        current_sum = current_sum - chocolate[i] + chocolate[i + m]
        if current_sum == d:
            count += 1
    
    return count

print(count_ways_to_divide(chocolate, d, m))
