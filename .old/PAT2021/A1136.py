a = input()

def is_palidrome(c):
    temp = c[::-1]
    if(temp == c): return True
    else: return False

flag = 0

for i in range(10):
    b = a[::-1]
    c = str(int(a) + int(b))
    print(a + " + " + b + " = " + c)
    if is_palidrome(c):
        print(c + " is a palindromic number.")
        flag = 1
        break
    a = c

if(flag == 0):
    print("Not found in 10 iterations.")