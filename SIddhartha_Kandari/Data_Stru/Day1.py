def birthday_chocolate(s, d, m):
    count = 0
    n = len(s)
    
    # Iterate over possible starting points of the segment
    for i in range(n - m + 1):
        # Calculate sum of the segment starting at i and of length m
        segment_sum = sum(s[i:i+m])
        
        # Check if segment sum equals d
        if segment_sum == d:
            count += 1
    
    return count

# Example usage:
chocolate_squares = [1, 2, 1, 3, 2]
birth_day = 3
birth_month = 2
result = birthday_chocolate(chocolate_squares, birth_day, birth_month)
print("Number of ways:", result)
