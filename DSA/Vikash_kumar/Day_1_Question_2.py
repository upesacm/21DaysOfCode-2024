#Day1 Question2:-
arr = []
arr = input("Enter the numbers with the space : ").split(" ")
k = int(input("Enter the value of k : "))
count = 0

for i in range(len(arr)):
    for j in range(i+1, len(arr)):
        if (int(arr[i]) + int(arr[j])) % k == 0:
            count += 1
print(f"The number of pairs where 1st<2nd and divisible by {k} = {count}")
