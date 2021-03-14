a = input()

def isPrime(a):
    a = int(a)
    if a <= 1: return False
    if a == 2: return True
    for i in range(2, int(a ** 1/2) + 1):
        if a % i == 0:
            return False
    return True

flag = True
while len(a) > 0:
    if isPrime(a):
        print(a, "Yes")
    else: 
        print(a, "No")
        flag = False
    a = a[1:]

if flag: print("All Prime!")

