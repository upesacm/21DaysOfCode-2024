def can_be_colored(vertices, edges):
    
    graph = {i: [] for i in range(1, vertices + 1)}
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    colors = {}

    def dfs(vertex, color):
        colors[vertex] = color
        for neighbor in graph[vertex]:
            if neighbor not in colors:
                if not dfs(neighbor, 3 - color):
                    return False
            elif colors[neighbor] == color:
                return False
        return True

    if not dfs(1, 1):
        return "NO"
    return "YES"

vertices = 4
edges = [(1, 2), (1, 3), (2, 4), (3, 4)]
print(can_be_colored(vertices, edges)) 
