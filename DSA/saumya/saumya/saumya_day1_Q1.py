def find_segments(arr, m, d):
    count = 0
    n = len(arr)
    for i in range(n - m + 1):
        # Sum the segment of length m starting at index i
        if sum(arr[i:i + m]) == d:
            count += 1
    
    return count

# Example:
arr = [2, 2, 1, 3, 2]
m = 2  # Raju's birthmonth
d = 4  # Raju's birthday

result = find_segments(arr, m, d)
print(result)  
# Output should be 2
