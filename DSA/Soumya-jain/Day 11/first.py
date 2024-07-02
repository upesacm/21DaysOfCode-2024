from collections import deque

def min_moves_to_reach_goal(grid, start, goal):
    # Check for invalid input
    if not grid or not grid[0]:
        return -1
    
    m, n = len(grid), len(grid[0])
    sx, sy = start
    gx, gy = goal
    
    # Check if start or goal is blocked
    if grid[sx][sy] == 'X' or grid[gx][gy] == 'X':
        return -1
    
    # Check if start is the same as goal
    if (sx, sy) == (gx, gy):
        return 0
    
    # BFS initialization
    queue = deque([(sx, sy, 0)])  # (x, y, distance)
    visited = [[False] * n for _ in range(m)]
    visited[sx][sy] = True
    
    # Possible directions: up, down, left, right
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    while queue:
        x, y, dist = queue.popleft()
        
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            
            if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny] and grid[nx][ny] == '.':
                if (nx, ny) == (gx, gy):
                    return dist + 1
                queue.append((nx, ny, dist + 1))
                visited[nx][ny] = True
    
    return -1  # Goal not reachable

# Example usage:
grid = [
    ['.', '.', '.'],
    ['.', 'X', '.'],
    ['.', '.', '.']
]

start = (0, 0)
goal = (2, 2)

print(min_moves_to_reach_goal(grid, start, goal))  # Output: 4
