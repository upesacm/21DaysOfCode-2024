arr = [1, 2, 3, 4, 5]
k = 3

def count_pairs_divisible_by_k(arr, k):
    remainder_count = [0] * k
    for num in arr:
        remainder = num % k
        remainder_count[remainder] += 1
    
    count = 0
    count += (remainder_count[0] * (remainder_count[0] - 1)) // 2
    for i in range(1, (k // 2) + 1):
        if i != k - i:
            count += remainder_count[i] * remainder_count[k - i]
    
    # If k is even, count pairs with remainder k/2
    if k % 2 == 0:
        count += (remainder_count[k // 2] * (remainder_count[k // 2] - 1)) // 2
    
    return count

print(count_pairs_divisible_by_k(arr, k))
