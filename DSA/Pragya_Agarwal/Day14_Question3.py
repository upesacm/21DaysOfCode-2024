def light(n, hallway):
    if n == 0:
        return -1
    
    count = 0
    i = 0
    while i<n:
        max_reach = i+hallway[i]
        if hallway[i] >= 0:
            count += 1
            i = max_reach+1
        else:
            return -1
            i += 1
        
    if i>=n and max_reach < n:
        return -1
    return count

n = int(input())
hallway = list(map(int,input().split()))
result = light(n, hallway)
print(result)

