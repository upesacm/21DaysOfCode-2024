from collections import defaultdict

class Graph:
    def __init__(self, nodes):
        self.graph = defaultdict(list)
        self.nodes = nodes

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def dfs_util(self, node, visited):
        visited[node] = True
        print(node, end=" ")

        for neighbor in self.graph[node]:
            if not visited[neighbor]:
                self.dfs_util(neighbor, visited)

    def dfs(self, start):
        visited = [False] * self.nodes
        self.dfs_util(start, visited)

def main():

    nodes = 6
    edges = [(0, 1), (0, 2), (1, 3), (1, 4), (2, 5)]
    start_node = 0

    graph = Graph(nodes)
    for u, v in edges:
        graph.add_edge(u, v)

    print("DFS order:")
    graph.dfs(start_node)

if __name__ == "__main__":
    main()

