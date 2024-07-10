from collections import deque
def is_bipartite(n, edges):
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u-1].append(v-1)
        adj[v-1].append(u-1)
    color = [-1] * n
    def bfs_check(src):
        queue = deque([src])
        color[src] = 0
        while queue:
            u = queue.popleft()
            
            for v in adj[u]:
                if color[v] == -1: 
                    color[v] = 1 - color[u]  
                    queue.append(v)
                elif color[v] == color[u]:
                    return False  
        return True
    for i in range(n):
        if color[i] == -1:
            if not bfs_check(i):
                return "NO"
    return "YES"
n = 4
edges = [(1, 2), (1, 3), (2, 4), (3, 4)]
print(is_bipartite(n, edges))
