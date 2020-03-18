num_in_English = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
num = input()
sum = 0
ans = []
for i in range(len(num)):
    sum += int(num[i])
# 更简洁的方法： a = sum([int(i) for i in input()])
sum_string = str(sum)
for i in range(len(sum_string)):
    ans.append(num_in_English[int(sum_string[i])])
print(" ".join(ans))