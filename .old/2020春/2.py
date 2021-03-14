n1, n2 = list(map(int, input().split())) # 运行超时，需要改写
num = {n1, n2}
dif = {abs(n1 - n2)}
n, m = list(map(int, input().split()))
player = []
flag = [1 for i in range(n)]
for _ in range(n):
    temp = list(map(int, input().split()))
    player.append(temp)
for i in range(m):
    for j in range(n):
        if flag[j] == 1:
            a = player[j][i]
            if a not in num and a in dif:
                for t in num:
                    dif.add(abs(t - a))
                num.add(a)
            else:
                flag[j] = 0
                print("Round #%d: %d is out." %(i+1, j+1))

ans = []
for i in range(n):
    if flag[i] == 1:
        ans.append(i+1)
if len(ans) == 0: 
    print("No winner.")
else:
    print("Winner(s): ", end='')
    print(" ".join(list(map(str, ans))))

                