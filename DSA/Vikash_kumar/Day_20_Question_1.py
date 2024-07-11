Day20-Question1-
from collections import deque

def is_bipartite(vertices, edges):
    # Initialize the graph as an adjacency list
    graph = {i: [] for i in range(1, vertices + 1)}
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    # Initialize color array, -1 indicates no color assigned
    color = [-1] * (vertices + 1)

    # Function to check if the graph is bipartite starting from a source vertex
    def bfs(source):
        queue = deque([source])
        color[source] = 0  # Start coloring the source vertex with color 0

        while queue:
            node = queue.popleft()
            current_color = color[node]

            for neighbor in graph[node]:
                if color[neighbor] == -1:  # If not colored, color with opposite color
                    color[neighbor] = 1 - current_color
                    queue.append(neighbor)
                elif color[neighbor] == current_color:  # If same color as current node
                    return False
        return True

    for vertex in range(1, vertices + 1):
        if color[vertex] == -1:  # If the vertex is not colored, start BFS
            if not bfs(vertex):
                return "NO"
    
    return "YES"

vertices = 4
edges = [(1, 2), (1, 3), (2, 4), (3, 4)]
print(is_bipartite(vertices, edges))  # Output: YES
