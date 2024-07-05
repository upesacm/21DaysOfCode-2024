def min_moves_to_non_decreasing(n, height):
    moves = 0
    for i in range(1, n):
        if height[i] < height[i-1]:
            moves += 1
    return moves

n = 6
height = [5, 6, 3, 3, 7, 1]
print(min_moves_to_non_decreasing(n, height))

