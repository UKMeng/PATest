n = int(input())
for i in range(n):
    print("Case #" + str(i+1) + ": ", end="")
    a, b, c = map(int, input().split())
    if(a + b > c): print("true")
    else: print("false")
    
