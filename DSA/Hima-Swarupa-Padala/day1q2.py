def divisible_pairs(arr, k):
    count = 0
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            if (arr[i] + arr[j]) % k == 0:
                count += 1
    return count

arr = [3, 5, 7, 1, 9, 6, 4]
k = 4
print(divisible_pairs(arr, k)) 

