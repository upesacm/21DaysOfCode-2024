Day20-Question2-
import heapq

def dijkstra(vertices, edges, start):
    graph = {i: [] for i in range(1, vertices + 1)}
    for u, v, w in edges:
        graph[u].append((v, w))
        graph[v].append((u, w))  

    distances = {i: float('inf') for i in range(1, vertices + 1)}
    distances[start] = 0
    priority_queue = [(0, start)]  

    while priority_queue:
        current_distance, current_vertex = heapq.heappop(priority_queue)

        if current_distance > distances[current_vertex]:
            continue
        for neighbor, weight in graph[current_vertex]:
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor)
    result = [distances[i] for i in range(1, vertices + 1)]
    return result

vertices = 4
edges = [(1, 2, 4), (1, 3, 1), (2, 4, 2), (3, 4, 3)]
start = 1
print(dijkstra(vertices, edges, start))  
