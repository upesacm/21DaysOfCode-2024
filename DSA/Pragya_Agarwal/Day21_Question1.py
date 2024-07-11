def weight(x,y,a):
    return abs(x*y - a[x-1] % a[y-1] - a[y-1] % a[x-1])

def cost(n,a):
    inf = float('inf')
    cost = [inf]*n
    min_cost=0
    visited =[False]*n
    
    cost[0]=0
    for i in range(n):
        u=-1
        for i in range(n):
            if not visited[i] and (u==-1 or cost[i]<cost[u]):
                u=i
        visited[u] = True
        min_cost += cost[u]
        
        for v in range(n):
            if not visited[v]:
                weigh = weight(u+1,v+1,a)
                if weigh<cost[v]:
                    cost[v] = weigh
    return min_cost
n = int(input())
a = list(map(int,input().split()))

result = cost(n,a)
print(result) 
