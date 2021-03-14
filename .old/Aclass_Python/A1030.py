from collections import defaultdict
num_city, num_road, start, destination = list(map(int, input().split()))
roads = defaultdict(list)
for _ in range(num_road):
    a, b, dis, c = list(map(int, input().split()))
    roads[a].append([b, dis, c])
    roads[b].append([a, dis, c])
vis = [False for _ in range(num_city)]
min_cost, min_dis = 999999, 999999
temp_cost, temp_distance = 0, 0
route, best_route = [start], [start]

def dfs(city):
    global min_cost, min_dis, temp_distance, temp_cost, destination, best_route, route
    if temp_distance > min_dis:
        return
    if city == destination:
        if temp_distance < min_dis:
            min_dis = temp_distance
            min_cost = temp_cost
            best_route = route.copy()
        elif temp_distance == min_dis and min_cost > temp_cost:
            min_cost = temp_cost
            best_route = route.copy()
        return
    for next, dis, cost in roads[city]:
        if not vis[next]:
            temp_cost += cost
            temp_distance += dis
            vis[next] = True
            route.append(next)
            dfs(next)
            temp_cost -= cost
            temp_distance -= dis
            vis[next] = False
            route.pop()

dfs(start)
print(" ".join(list(map(str, best_route + [min_dis, min_cost]))))