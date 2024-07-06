def min_moves(height):
    moves = 0
    while True:
        removed = False
        new_height = [height[0]]
        for i in range(1, len(height)):
            if height[i] >= new_height[-1]:
                new_height.append(height[i])
            else:
                removed = True
        if not removed:
            break
        height = new_height
        moves += 1
    return moves

n = 3
height = [1, 2, 1]
print(min_moves(height))  # Output: 1
