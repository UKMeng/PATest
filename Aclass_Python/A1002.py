'''
from decimal import Decimal

def getPoly(a):
    x = 0
    A = {}
    length = a[0] * 2
    a = a[1:]
    while x < length:
        A[a[x]] = a[x + 1]
        x += 2
    return A


def add_dict(A, B):
    count = len(B)
    for i in A.keys():
        if i in B.keys():
            B[i] += A[i]
            if B[i] == 0.0:
                count -= 1
        else:
            B[i] = A[i]
            count += 1
    sorted(B, reverse = True)
    return B, count

def main():
    a = input()
    a = [Decimal(num) for num in a.split()]
    b = input()
    b = [Decimal(num) for num in b.split()]
    A = getPoly(a)
    B = getPoly(b)
    ans, anscount = add_dict(A, B)
    res = []
    for k, v in ans.items():
        if v != 0:
            res.append((k, v))
    res = sorted(res, key=lambda x: x[0], reverse = True)
    print(len(res), end='')
    for i in range(len(res)):
        a, n = res[i]
        print(" {} {}".format(int(a), round(n, 1)), end='')    
    # 直接从dict输出结果有一未知漏洞，导致测试点2通不过
    # print(f'{anscount}', end='')
    # for i in ans.keys():
        # if ans[i] != 0.0:
            # print(f' {int(i)} {round(ans[i], 1)}', end='')    
if __name__ == "__main__":
    main()
'''

poly = [0 for _ in range(1001)]

def add():
    global poly
    line = input().split()[1:]
    i = 0
    while i < len(line) - 1:
        poly[int(line[i])] += float(line[i + 1])
        i += 2

add()
add()

count = 0
for i in range(1000, -1, -1):
    if poly[i] != 0:
        count += 1
    
print(count, end='')
for i in range(1000, -1, -1):
    if poly[i] != 0:
        print(" %d %.1f" % (i, poly[i]), end='')