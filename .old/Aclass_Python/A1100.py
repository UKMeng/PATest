number = ["tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov"\
    , "dec"]
high_number = ["tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", \
    "lok", "mer", "jou"]
case_number = int(input())
for _ in range(case_number) :
    temp = input()
    if temp.isnumeric():
        num = int(temp)
        ans = []
        if num != 0:
            while num != 0:
                ans = [num % 13] + ans
                num //= 13
            if len(ans) == 2:
                ans[0] = high_number[ans[0] - 1]
                if ans[1] != 0:
                    ans[1] = number[ans[1]]
                else:
                    ans.pop()
            else:
                ans[0] = number[ans[0]]
        else:
            ans = ['tret']
        print(" ".join(ans)) 
    else:
        a = list(temp.split())
        if len(a) == 2:
            ans = high_number.index(a[0])
            ans = (ans + 1) * 13 + number.index(a[1])
            print(ans)
        else:
            if a[0] in high_number:
                print((high_number.index(a[0]) + 1) * 13)
            else:
                print(number.index(a[0]))

