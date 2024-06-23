arr = [1, 2, 3, 4, 5]
k = 3

def count_pairs_divisible_by_k(arr, k):
    rem_count = [0] * k
    for num in arr:
        rem = num % k
        rem_count[rem] += 1
    
    count = 0
    count += (rem_count[0] * (rem_count[0] - 1)) // 2
    for i in range(1, (k // 2) + 1):
        if i != k - i:
            count += rem_count[i] * rem_count[k - i]
    
    # If k is even then count pairs with remainder, k/2
    if k % 2 == 0:
        count += (rem_count[k // 2] * (rem_count[k // 2] - 1)) // 2
    
    return count

print(count_pairs_divisible_by_k(arr, k))
#the output should be 4
