def divisible_pairs(arr, k):
    count = 0
    n = len(arr)
    
    for i in range(n):
        for j in range(i + 1, n):
            if (arr[i] + arr[j]) % k == 0:
                count += 1
    
    return count

array = list(map(int, input("Enter the elements of the array separated by spaces: ").split()))
k = int(input("Enter the value of k: "))
result = divisible_pairs(array, k)
print(f"The number of valid (i, j) pairs is: , {result}")

