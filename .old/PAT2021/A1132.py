k = int(input())
for i in range(k):
    z = input()
    l = len(z) // 2
    a = z[:l]
    b = z[l:]
    if(int(b) == 0):
        print("No")
        continue
    if int(z) % (int(a) * int(b)) == 0:
        print("Yes")
    else:
        print("No")
