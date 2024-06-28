def police_stations(station, p):
    station.sort()
    n = len(station)
    res = float('inf')
    
    for i in range(n):
        left, right = i, n - 1
        while left <= right:
            mid = (left + right) // 2
            if can_buy(station, p, mid, i):
                res = min(res, mid)
                right = mid - 1
            else:
                left = mid + 1
                
    return res

def can_buy(station, p, mid, i):
    cnt = 0
    for j in range(i, len(station)):
        cnt += min(mid, station[j] - station[j - 1]) if j > 0 else mid
        if cnt >= p:
            return True
    return False

print(police_stations([6, 8], 5)) 
print(police_stations([-1, 8], 4)) 
print(police_stations([6, 12, 9], 40))  