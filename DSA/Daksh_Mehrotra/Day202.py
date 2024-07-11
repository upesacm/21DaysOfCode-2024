import heapq
def dijkstra(n, edges, start):
    adj = [[] for _ in range(n)]
    for u, v, w in edges:
        adj[u-1].append((v-1, w))
        adj[v-1].append((u-1, w))
    dist = [float('inf')] * n
    dist[start-1] = 0
    pq = [(0, start-1)]
    while pq:
        current_dist, u = heapq.heappop(pq)
        if current_dist > dist[u]:
            continue
        for v, weight in adj[u]:
            distance = current_dist + weight
            if distance < dist[v]:
                dist[v] = distance
                heapq.heappush(pq, (distance, v))
    return dist
n = 4
edges = [(1, 2, 4), (1, 3, 1), (2, 4, 2), (3, 4, 3)]
start = 1
print(dijkstra(n, edges, start))  