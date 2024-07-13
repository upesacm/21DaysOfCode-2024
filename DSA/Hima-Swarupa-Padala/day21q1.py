class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1

def calculate_weight(x, y, A):
    return abs(x * y - A[x-1] % A[y-1] - A[y-1] % A[x-1])

def minimum_spanning_tree_cost(N, A):
    edges = []
    for x in range(1, N+1):
        for y in range(x+1, N+1):
            weight = calculate_weight(x, y, A)
            edges.append((weight, x-1, y-1))

    edges.sort()
    
    dsu = DSU(N)
    mst_cost = 0
    edges_in_mst = 0
    
    for weight, u, v in edges:
        if dsu.find(u) != dsu.find(v):
            dsu.union(u, v)
            mst_cost += weight
            edges_in_mst += 1
            if edges_in_mst == N - 1:
                break
    
    return mst_cost

N = 5
A = [1, 3, 5, 5, 1]
print(minimum_spanning_tree_cost(N, A))  
N = 3
A = [1, 1, 1]
print(minimum_spanning_tree_cost(N, A)) 
