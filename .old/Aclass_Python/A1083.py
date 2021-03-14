n = int(input())
data = []
for _ in range(n):
    data.append(list(input().split()))
a1, a2 = map(int, input().split())
data = [i for i in data if a1 <= int(i[2]) <= a2]
if len(data) == 0:
    print("NONE")
else:
    data.sort(key=lambda x: int(x[2]), reverse=True)
    for item in data:
        print(item[0], item[1])