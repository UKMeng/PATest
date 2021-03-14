digit = ["ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"]
num, ans = input(), []
if num == "0":
    print("ling")
else:
    if num[0] == "-":
        print("Fu", end=" ")
        num = num[1:]
    num = num[::-1]
    for i, j in enumerate(num):
        if i % 4 == 1 and (num[i] != "0"):
            ans.append("Shi")
        elif i % 4 == 2 and (num[i] != "0"):
            ans.append("Bai")
        elif i % 4 == 3 and (num[i] != "0"):
            ans.append("Qian")
        elif i == 4:
            ans.append("Wan")
        elif i == 8:
            ans.append("Yi")
        if j != "0" or (i >= 1 and num[i-1] != "0"):
            ans.append(digit[int(j)])
    print(" ".join(list(map(str, ans[::-1]))))
