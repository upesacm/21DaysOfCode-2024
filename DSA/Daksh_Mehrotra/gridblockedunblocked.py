from collections import deque

def min_moves(grid, start, goal):
    rows, cols = len(grid), len(grid[0])
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  

    queue = deque([(start, 0)]) 
    visited = set()
    visited.add(start)

    while queue:
        (current_row, current_col), moves = queue.popleft()

        if (current_row, current_col) == goal:
            return moves

        for dr, dc in directions:
            new_row, new_col = current_row + dr, current_col + dc

            if 0 <= new_row < rows and 0 <= new_col < cols and (new_row, new_col) not in visited:
                if grid[new_row][new_col] == '.':
                    visited.add((new_row, new_col))
                    queue.append(((new_row, new_col), moves + 1))

    return -1 
grid = [
    ['.', '.', '.'],
    ['.', 'X', '.'],
    ['.', '.', '.']
]
start = (0, 0)
goal = (2, 2)
print(min_moves(grid, start, goal))  
