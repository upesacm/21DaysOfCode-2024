import heapq

def dijkstra(num_vertices, edges, start):
    adj_list = [[] for _ in range(num_vertices + 1)]
    for u, v, w in edges:
        adj_list[u].append((v, w))
        adj_list[v].append((u, w))
    
    distances = [float('inf')] * (num_vertices + 1)
    distances[start] = 0
    
    pq = [(0, start)]
    
    while pq:
        current_distance, node = heapq.heappop(pq)
        
        if current_distance > distances[node]:
            continue
        
        for neighbor, weight in adj_list[node]:
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    
    return distances[1:] 

num_vertices = 4
edges = [(1, 2, 4), (1, 3, 1), (2, 4, 2), (3, 4, 3)]
start = 1
print(dijkstra(num_vertices, edges, start))  
