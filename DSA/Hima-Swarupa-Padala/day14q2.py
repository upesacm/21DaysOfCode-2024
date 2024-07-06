from collections import defaultdict

def arrange_horses(n, m, data):

    graph = defaultdict(list)
    for a, b in data:
        graph[b].append(a)

    stack = []
    visited = [False] * n

    def dfs(node):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor)
        stack.append(node)

    for i in range(n):
        if not visited[i]:
            dfs(i)

    stack.reverse()

    return stack

n = 4
m = 4
data = [(3, 1), (0, 2), (2, 1), (0, 3)]

result = arrange_horses(n, m, data)

print(result)
