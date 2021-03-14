from collections import defaultdict
from copy import deepcopy

a = input().split()
cities_num, routes_num, start_city = int(a[0]), int(a[1]), a[2]
happy = defaultdict(int)
roads = defaultdict(list)
visited = defaultdict(int)
best = [999999, -99999, 0, []]

for _ in range(cities_num - 1):
    a = input().split()
    happy[a[0]] = int(a[1])
for _ in range(routes_num):
    a = input().split()
    roads[a[0]].append((a[1], int(a[2])))
    roads[a[1]].append((a[0], int(a[2])))

def dfs(city, temp_cost, temp_happy, temp_path):
    if city == 'ROM':
        if best[0] > temp_cost:
            best[0] = temp_cost
            best[1] = temp_happy
            best[2] = 1
            best[3] = deepcopy(temp_path)
        elif temp_cost == best[0]:
            best[2] += 1
            if best[1] < temp_happy:
                best[1] = temp_happy
                best[3] = deepcopy(temp_path)
            elif best[1] == temp_happy:
                if len(best[3]) > len(temp_path):
                    best[3] = deepcopy(temp_path)

    for to, cost in roads[city]:
        if visited[to] == 0:
            visited[to] = 1
            temp_path.append(to)
            dfs(to, cost + temp_cost, happy[to] + temp_happy, temp_path)
            temp_path.pop()
            visited[to] = 0

dfs(start_city, 0, 0, [])
print(best[2], best[0], best[1], best[1] // len(best[3]))
print('->'.join([start_city] + best[3]))