def count_pairs_divisible_by_k(arr, k):
    remainder_count = [0] * k
    count = 0
    for num in arr:
        remainder = num % k
        complement = (k - remainder) % k
        count += remainder_count[complement]
        remainder_count[remainder] += 1
    return count
arr = [1, 3, 2, 6, 1, 2]
k = 3
result = count_pairs_divisible_by_k(arr, k)
print(result) 