_ = int(input())
nums = set(list(map(int, input().split())))
for i in range(1, 999999999):
    if i not in nums:
        print(i)
        break