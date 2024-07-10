# Popular Bipartite Graph Check (2-Coloring Problem)

def is_bipartite(num_vertices, edges):
    from collections import deque
    
    adj_list = [[] for _ in range(num_vertices + 1)]
    for u, v in edges:
        adj_list[u].append(v)
        adj_list[v].append(u)
    
    colors = [-1] * (num_vertices + 1)
    
    def bfs(start):
        queue = deque([start])
        colors[start] = 0  
        
        while queue:
            node = queue.popleft()
            for neighbor in adj_list[node]:
                if colors[neighbor] == -1: 
                    colors[neighbor] = 1 - colors[node]  
                    queue.append(neighbor)
                elif colors[neighbor] == colors[node]:  
                    return False
        return True
    
    for i in range(1, num_vertices + 1):
        if colors[i] == -1:  
            if not bfs(i):
                return "NO"
    
    return "YES"

num_vertices = 4
edges = [(1, 2), (1, 3), (2, 4), (3, 4)]
print(is_bipartite(num_vertices, edges))
