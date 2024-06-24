arr = [1, 3, 2, 6, 1, 2]
k = 3

result = 0

for i in range(len(arr)):
    for j in range(i + 1, len(arr)):
        if (arr[i] + arr[j]) % k == 0:
            result += 1

print("The number of (i,j) pairs:",result) 
