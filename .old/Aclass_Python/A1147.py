query, n = list(map(int, input().split()))
min_flag, max_flag = 1, 1

def dfs(index, ans):
    global min_flag, max_flag, a
    if index * 2 + 1 >= n:
        ans.append(a[index])
        return
    if index * 2 + 1 < n:
        if a[index] < a[index * 2 + 1]: max_flag = 0
        if a[index] > a[index * 2 + 1]: min_flag = 0
        dfs(index * 2 + 1, ans)
    if index * 2 + 2 < n:
        if a[index] < a[index * 2 + 2]: max_flag = 0
        if a[index] > a[index * 2 + 2]: min_flag = 0
        dfs(index * 2 + 2, ans)
    ans.append(a[index])

for _ in range(query):
    min_flag, max_flag = 1, 1
    a = list(map(int, input().split()))
    ans = []
    dfs(0, ans)
    if min_flag == 1: print("Min Heap")
    elif max_flag == 1: print("Max Heap")
    else: print("Not Heap")
    print(" ".join(list(map(str, ans))))