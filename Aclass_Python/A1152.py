''' 超时的判断素数的方法
def isPrime(a):
    if a == 2: return True
    if a <= 1: return False
    for i in range(2, int(a ** 1/2) + 1):
        if a % i == 0:
            return False
    return True
'''
# 优化的判断素数算法
def isPrime(a):
    if a == 1: return False
    if a == 2 or a == 3 : return True
    if a % 2 == 0: return False
    for i in range(3, int(a ** 0.5) + 1, 2):
        if a % i == 0:
            return False
    return True

def main():
    length, tar = map(int, input().split())
    string = input()
    flag = False
    for i in range(length - tar + 1):
        temp = string[i: i + tar]
        if isPrime(int(temp)):
            flag = True
            print(temp)
            break
    if flag == False:
        print("404")
    

if __name__ == "__main__":
    main()