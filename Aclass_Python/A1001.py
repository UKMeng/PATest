'''
a, b = map(int, input().split())
c = str(a + b)
l = len(c)
for i in range(0, l):
    print(c[i], end = "")
    if c[i] == '-' :
        continue
    if (i + 1) % 3 == l%3 and (i + 1) != l:
        print(",", end = "")

'''
n = input().split()
print(format(int(n[0]) + int(n[1]), ','))
