from collections import defaultdict, deque

class Graph:
    def __init__(self, nodes):
        self.graph = defaultdict(list)
        self.nodes = nodes

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def bfs(self, start):

        distances = {}
        for i in range(1, self.nodes + 1):
            distances[i] = -1
        visited = [False] * self.nodes

        queue = deque()
        queue.append(start)
        distances[start] = 0
        visited[start - 1] = True

        while queue:
            node = queue.popleft()
            for neighbor in self.graph[node]:
                if not visited[neighbor - 1]:
                    queue.append(neighbor)
                    visited[neighbor - 1] = True
                    distances[neighbor] = distances[node] + 1

        return distances

def main():

    nodes = 7
    edges = [(1, 2), (1, 3), (2, 4), (2, 5), (3, 6), (3, 7)]
    start_node = 1

    graph = Graph(nodes)
    for u, v in edges:
        graph.add_edge(u, v)

    shortest_reach = graph.bfs(start_node)

    print("Shortest reach from starting node:")
    print(shortest_reach)

if __name__ == "__main__":
    main()
