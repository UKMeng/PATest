from collections import defaultdict

num_online, num_mid, num_final = list(map(int, input().split()))
online = defaultdict(lambda: -1)
mid = defaultdict(lambda: -1)
final = defaultdict(lambda: -1)
G = defaultdict(lambda: -1)

for _ in range(num_online):
    name, score = input().split()
    online[name] = int(score)
for _ in range(num_mid):
    name, score = input().split()
    mid[name] = int(score)
for _ in range(num_final):
    name, score = input().split()
    final[name] = int(score)

name_lists = set(list(online.keys()) + list(mid.keys()) + list(final.keys()))
for name in name_lists:
    mid_score = mid[name] if mid[name] != -1 else 0
    final_score = final[name] if final[name] != -1 else 0
    G[name] = round(mid_score * 0.4 + final_score * 0.6) if mid_score > final_score else final_score

lists = [i for i in name_lists if online[i] >= 200 and G[i] >= 60]
lists.sort(key=lambda x: (-G[x], x))

for i in lists:
    print("%s %s %s %s %s" % (i, online[i], mid[i], final[i], G[i]))
    