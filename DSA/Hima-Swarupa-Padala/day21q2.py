import sys
import collections

sys.setrecursionlimit(100000)

def add_edge(adj_list, u, v):
    adj_list[u].append(v)
    adj_list[v].append(u)

def dfs(node, parent, depth, adj_list, depths, parents):
    depths[node] = depth
    parents[node][0] = parent
    for next_node in adj_list[node]:
        if next_node != parent:
            dfs(next_node, node, depth + 1, adj_list, depths, parents)

def preprocess_lca(n, parents):
    LOG = len(parents[0])
    for k in range(1, LOG):
        for v in range(n):
            if parents[v][k-1] != -1:
                parents[v][k] = parents[parents[v][k-1]][k-1]
            else:
                parents[v][k] = -1

def get_lca(u, v, depths, parents):
    LOG = len(parents[0])
    if depths[u] < depths[v]:
        u, v = v, u
    diff = depths[u] - depths[v]
    for k in range(LOG):
        if (diff >> k) & 1:
            u = parents[u][k]
    if u == v:
        return u
    for k in range(LOG-1, -1, -1):
        if parents[u][k] != parents[v][k]:
            u = parents[u][k]
            v = parents[v][k]
    return parents[u][0]

def get_distance(u, v, depths, parents):
    lca = get_lca(u, v, depths, parents)
    return depths[u] + depths[v] - 2 * depths[lca]

def main():
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    N = int(data[idx])
    idx += 1
    
    adj_list = collections.defaultdict(list)
    for _ in range(N - 1):
        u = int(data[idx]) - 1
        v = int(data[idx + 1]) - 1
        idx += 2
        add_edge(adj_list, u, v)
    
    A = list(map(int, data[idx:idx + N]))
    
    depths = [-1] * N
    LOG = 16
    parents = [[-1] * LOG for _ in range(N)]
    
    dfs(0, -1, 0, adj_list, depths, parents)
    preprocess_lca(N, parents)
    
    total_sum = 0
    for i in range(N):
        for j in range(i + 1, N):
            if A[i] == A[j]:
                total_sum += get_distance(i, j, depths, parents)
    
    print(total_sum)

if __name__ == "__main__":
    main()
