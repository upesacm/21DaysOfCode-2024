Day14-Quiz2-Question2-
from collections import deque, defaultdict

def smallest_order(n, m, pairs):
    graph = defaultdict(list)
    in_degree = [0] * n

    for i, j in pairs:
        graph[i].append(j)
        in_degree[j] += 1

    zero_in_degree = deque()

    for i in range(n):
        if in_degree[i] == 0:
            zero_in_degree.append(i)

    order = []

    while zero_in_degree:
        zero_in_degree = deque(sorted(zero_in_degree))
        node = zero_in_degree.popleft()
        order.append(node)

        for neighbor in graph[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                zero_in_degree.append(neighbor)

    if len(order) != n:
        return []

    return order

n = int(input("Enter the number of horses: "))
m = int(input("Enter the number of comparisons: "))
pairs = [tuple(map(int, input().split(" "))) for _ in range(m)]

result = smallest_order(n, m, pairs)
print(" ".join(map(str, result[::-1])))
