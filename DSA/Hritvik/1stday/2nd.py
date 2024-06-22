def count(arr, k):
  n = len(arr)
  count = 0
  for i in range(n):
    for j in range(i + 1, n):
      if (arr[i] + arr[j]) % k == 0:
        count += 1
  return count
arr = [1, 3, 2, 6, 1, 2]
k = 3

result = count(arr, k)
print("Total pairs is", result)
