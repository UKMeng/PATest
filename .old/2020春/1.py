s = input()

def isPrime(a):
    if a == 1: return False
    if a == 2: return True
    for i in range(3, int(a ** 0.5)):
        if a % i == 0: 
            return False
    return True

all_flag = 1
for i in range(len(s)):
    flag = isPrime(int(s))
    if flag:
        print(s,"Yes")
    else:
        print(s,"No")
        all_flag = 0
    s = s[1:]

if all_flag == 1: print("All Prime!")