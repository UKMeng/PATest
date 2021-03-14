num_vertice, num_edge = list(map(int, input().split()))
edges = [[] for _ in range(num_vertice + 1)]
for _ in range(num_edge):
    a, b = list(map(int, input().split()))
    edges[a].append(b)
    edges[b].append(a)

degree = [len(edges[i]) for i in range(num_vertice + 1)]
odd = len([i for i in degree if i % 2 == 1])

#dfs
count = 0
visited = [False for i in range(num_vertice + 1)]
visited[1] = True
def dfs(i):
    global count
    count += 1
    for neighbor in edges[i]:
        if not visited[neighbor]:
            visited[neighbor] = True
            dfs(neighbor)

print(" ".join(list(map(str, degree[1:]))))
if odd == 0:
    dfs(1)
    if count == num_vertice:
        print("Eulerian")
    else:
        print("Non-Eulerian")
elif odd == 2:
    dfs(1)
    if count == num_vertice:
        print("Semi-Eulerian")
    else:
        print("Non-Eulerian")
else:
    print("Non-Eulerian")