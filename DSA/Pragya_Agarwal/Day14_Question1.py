def decreasing(n,height):
    moves = 0
    for i in range(1,n):
        if height[i]<height[i-1]:
            moves += 1
    return moves

n = int(input())  
height_input = input().split()  
height = []
for h in height_input:
    height.append(int(h))

result = decreasing(n, height)
print(result) 
