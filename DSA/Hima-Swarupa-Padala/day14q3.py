def min_bulbs_to_light_hallway(n, hallway):
   
    coverage = []
    
    for i in range(n):
        if hallway[i] != -1:
            start = max(0, i - hallway[i])
            end = min(n - 1, i + hallway[i])
            coverage.append((start, end))

    coverage.sort(key=lambda x: (x[0], x[1]))
    
    num_bulbs = 0
    current_end = 0
    i = 0
    
    while i < len(coverage) and current_end < n:
        
        if coverage[i][0] > current_end:
            return -1  
        
        max_end = current_end
        while i < len(coverage) and coverage[i][0] <= current_end:
            max_end = max(max_end, coverage[i][1])
            i += 1

        num_bulbs += 1
        current_end = max_end + 1  

    if current_end >= n:
        return num_bulbs
    else:
        return -1

n = 6
hallway = [-1, 2, 2, -1, 0, 0]
print(min_bulbs_to_light_hallway(n, hallway))  

def min_bulbs_to_turn_on(n, hallway):
    bulbs_on = 0
    last_bulb = -1
    i = 0
    
    while i < n:
        if hallway[i] == -1:
            i += 1
            continue
        
        start = max(i - hallway[i], 0)
        end = min(i + hallway[i], n - 1)
        
        if start > last_bulb:
            return -1
        
        bulbs_on += 1
        last_bulb = end
        i = end + 1
    
    return bulbs_on

n = 9
hallway2 = [2, 3, 4, -1, 2, 0, 0, -1, 0]
print(min_bulbs_to_turn_on(n, hallway2))  
