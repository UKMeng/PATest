n = int(input())
ropes = sorted(list(map(int, input().split())))
length = (ropes[0] + ropes[1]) / 2
for i in range(2, n):
    length = (length + ropes[i]) / 2
print(int(length))