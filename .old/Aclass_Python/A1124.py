'''
forwards, skip, win = list(map(int, input().split()))
appeared = set()
ans = []
index = 0
handled = 0
while handled < forwards:
    name = input()
    handled += 1
    index += 1
    if index == win or index - win == skip:
        while name in appeared:
            name = input()
            handled += 1
        ans.append(name)
        index = win
        appeared.add(name)
if len(ans) == 0: print("Keep going...")
else:
    for i in ans:
        print(i)
'''
forwards, skip, win = list(map(int, input().split()))
appeared = set()
ans = []
index = 0
while index < forwards:
    name = input()
    index += 1
    if name in appeared: win += 1
    elif index == win:
        ans.append(name)
        win += skip
        appeared.add(name)
if len(ans) == 0: print("Keep going...")
else:
    for i in ans:
        print(i)