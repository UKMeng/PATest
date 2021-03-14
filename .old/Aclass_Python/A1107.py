n = int(input())
hobby = [0 for i in range(1001)]
father = [i for i in range(n + 1)]
isRoot = [0 for i in range(n + 1)]

def findFather(son):
    if son != father[son]:
        father[son] = findFather(father[son])
    return father[son]

for i in range(n):
    hobbies = list(map(int, input().split()[1:]))
    for j in hobbies:
        if hobby[j] == 0:
            hobby[j] = i + 1
        else:
            father[findFather(i + 1)] = findFather(hobby[j])
            

for i in range(n):
    isRoot[findFather(i + 1)] += 1
ans = []
for i in isRoot:
    if i != 0:
        ans.append(i)
print(len(ans))
print(" ".join(list(map(str, sorted(ans, reverse=True)))))