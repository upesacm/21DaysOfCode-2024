def min_max_value(str):
    n = len(str)
    total_x = str.count('x')
    total_y = str.count('y')
    
    min_cost = float('inf')
    
    left_x = 0
    left_y = 0
    
    for i in range(n + 1):
        if i > 0:
            if str[i - 1] == 'x':
                left_x += 1
            else:
                left_y += 1
        
        right_x = total_x - left_x
        right_y = total_y - left_y
        
        cost = max(right_x, left_y)
        min_cost = min(min_cost, cost)
    
    return min_cost

print(min_max_value("yxxyxxyxxyxxy")) 
