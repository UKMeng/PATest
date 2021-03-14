str = input()   # 字符串处理，稍微有点贪心
N = len(str)
n1 = int((N + 2) / 3)
n2 = N - 2 * n1
a1 = str[0: n1]
a2 = str[n1: n1 + n2]
a3 = str[n1 + n2:]
for i in range(n1):
    if(i + 1 != n1):
        print(a1[i] + n2 * ' ' + a3[n1 - 1 - i])
    else: print(a1[i] + a2 + a3[0])
