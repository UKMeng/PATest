n = int(input())
num = list(map(int, input().split()))
min_flag = True
max_flag = True
ans = []
index = 1
def compare(a, b):
    global min_flag, max_flag
    if num[a] > num[b]:
        min_flag = False
    elif num[a] < num[b]:
        max_flag = False

def dfs(index, path):
    if index * 2 + 1 >= n and index * 2 + 2 >= n:
        ans.append(path.copy())
        return
    if index * 2 + 2 < n:
        compare(index, index * 2 + 2)
        path.append(num[index * 2 + 2])
        dfs(index * 2 + 2, path)
        path.pop()
    if index * 2 + 1 < n:
        compare(index, index * 2 + 1)
        path.append(num[index * 2 + 1])
        dfs(index * 2 + 1, path)
        path.pop()

temp_path = [num[0]]
dfs(0, temp_path)
for path in ans:
    print(" ".join(list(map(str, path))))
if min_flag:
    print("Min Heap")
elif max_flag:
    print("Max Heap")
else:
    print("Not Heap")