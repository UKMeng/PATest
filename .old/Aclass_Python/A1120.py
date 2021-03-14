_ = input()
num = list(input().split())
ans_set = set()
for n in num:
    sum = 0
    for i in range(len(n)):
        sum += int(n[i])
    ans_set.add(sum)
ans_list = sorted(list(ans_set))
print(len(ans_list))
print(" ".join(list(map(str, ans_list))))