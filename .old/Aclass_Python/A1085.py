n, para = list(map(int, input().split()))
seq = sorted(list(map(int, input().split())))
ans = 0
for i, j in enumerate(seq):
    while i + ans < n and seq[i + ans] <= j * para:
        ans += 1
print(ans)
