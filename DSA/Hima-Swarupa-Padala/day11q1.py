from collections import deque

def is_valid(x, y, grid):

    return 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] != 1

def min_moves(grid, start, goal):

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    queue = deque([(start[0], start[1], 0)])  
    visited = set()
    visited.add(start)

    while queue:
        x, y, moves = queue.popleft()

        if (x, y) == goal:
            return moves

        for i in range(4):
            new_x, new_y = x + dx[i], y + dy[i]
            if is_valid(new_x, new_y, grid) and (new_x, new_y) not in visited:
                queue.append((new_x, new_y, moves + 1))
                visited.add((new_x, new_y))
    return -1

grid = [
    ['.', '.', '.'],
    ['.', 'X', '.'],
    ['.', '.', '.']
]
start = (0, 0)
goal = (2, 2)

result = min_moves(grid, start, goal)
if result != -1:
    print(result)
else:
    print("Goal is not reachable")
