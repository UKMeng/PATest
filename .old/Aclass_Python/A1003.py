num_city, num_road, start, end = map(int, input().split())
res_num_city = list(map(int, input().split()))
roads = [[] for _ in range(num_city)]
for _ in range(num_road):
    temp = list(map(int, input().split()))
    roads[temp[0]].append((temp[1], temp[2]))
    roads[temp[1]].append((temp[0], temp[2]))

max_res, min_road, min_dis = 0, 0, 99999
temp_dis, temp_res = 0, res_num_city[start]
visited = {start}

def dfs(city):
    global end, temp_dis, temp_res, min_dis, min_road, max_res
    if city == end:
        if temp_dis < min_dis:
            min_dis = temp_dis
            min_roads = 1
            max_res = temp_res
        elif temp_dis == min_dis:
            min_roads += 1
            if temp_res > max_res:
                max_res = temp_res
        return

    for next_city, distance in roads[city]:
        if next_city not in visited:
            visited.add(next_city)
            temp_dis += distance
            temp_res += res_num_city[next_city]
            dfs(next_city)
            temp_dis -= distance
            temp_res -= res_num_city[next_city]
            visited.remove(next_city)

dfs(start)
print(min_road, max_res)