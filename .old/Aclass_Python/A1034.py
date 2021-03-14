from collections import defaultdict

def dfs(name):
    global head, whole_weight, graph, visited, max_person_weight, num, roads_visited
    if not visited[name]:
        num += 1
        visited[name] = True
    for person, time in graph[name].items():
        if not roads_visited[name][person]:
            whole_weight += time
            roads_visited[name][person] = True
            roads_visited[person][name] = True
            if weight[person] > max_person_weight:
                max_person_weight = weight[person]
                head = person
            dfs(person)

num_calls, threshold = list(map(int, input().split()))
graph = defaultdict(lambda: defaultdict(int))
visited = defaultdict(bool)
roads_visited = defaultdict(lambda: defaultdict(bool))
ans = []
for _ in range(num_calls):
    info = input().split()
    graph[info[0]][info[1]] += int(info[2])
    graph[info[1]][info[0]] += int(info[2])
weight = {i: sum(graph[i].values()) for i in graph.keys()}

for i in graph.keys():
    if not visited[i]:
        num = 0
        whole_weight = 0
        head = i
        max_person_weight = weight[i]
        dfs(i)
        if whole_weight > threshold and num > 2:
            ans.append([head, num])

print(len(ans))
ans.sort(key=lambda x:x[0])
for i, j in ans:
    print(i, j)