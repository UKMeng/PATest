# input
num_city, num_road, start_city, end_city = map(int, input().split())
power = list(map(int, input().split()))
roads = [[] for _ in range(num_city)]
for _ in range(num_road):
    a = list(map(int, input().split()))
    roads[a[0]].append((a[1], a[2]))
    roads[a[1]].append((a[0], a[2]))
# 定义变量
min_road, max_power, min_distance = 0, 0, 999999
temp_distance, temp_power = 0, power[start_city]
visited = {start_city}

def dfs(city):
    global end_city, temp_distance, min_distance, temp_power, min_road, max_power, visited
    if city == end_city:
        if temp_distance < min_distance:
            min_distance = temp_distance
            min_road = 1
            max_power = temp_power
        elif temp_distance == min_distance:
            min_road += 1
            if temp_power > max_power:
                max_power = temp_power
        return

    for next_city, distance in roads[city]:
        if next_city not in visited:
            visited.add(next_city)
            temp_distance += distance
            temp_power += power[next_city]
            dfs(next_city)
            temp_distance -= distance
            temp_power -= power[next_city]
            visited.remove(next_city)

dfs(start_city)
print(min_road, max_power)