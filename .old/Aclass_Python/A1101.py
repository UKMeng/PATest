# 一直超时一直爽
n = int(input())
num = list(map(int, input().split()))
left, right = [0 for _ in range(n)], [0 for _ in range(n)]
MAX, MIN = num[0], num[-1]
ans = []
for i in range(n):
    if num[i] > MAX: MAX = num[i]
    left[i] = MAX
    if num[n-1-i] < MIN: MIN = num[n-1-i]
    right[n-1-i] = MIN
for i in range(n):
    if left[i] <= num[i] <= right[i]:
        ans.append(num[i])
print(len(ans))
print(" ".join(list(map(str, ans))))
