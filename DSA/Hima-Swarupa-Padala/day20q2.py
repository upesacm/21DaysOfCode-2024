import heapq

def dijkstra(graph, start):

    distances = [float('inf')] * len(graph)
    distances[start] = 0

    min_heap = [(0, start)]
    
    while min_heap:

        curr_dist, curr_node = heapq.heappop(min_heap)

        for neighbor, weight in graph[curr_node]:
            new_dist = curr_dist + weight
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                heapq.heappush(min_heap, (new_dist, neighbor))
    
    return distances

def main():

    vertices = 4
    edges = [(1, 2, 4), (1, 3, 1), (2, 4, 2), (3, 4, 3)]
    start_node = 1
    
    graph = [[] for _ in range(vertices)]
    for u, v, w in edges:
        graph[u - 1].append((v - 1, w))
        graph[v - 1].append((u - 1, w))
    
    shortest_distances = dijkstra(graph, start_node - 1)

    print(shortest_distances)

if __name__ == "__main__":
    main()

