num = int(input())
pre = list(map(int, input().split()))
if num == 1:
    print("YES")
    print(pre[0])
else:
    if pre[1] > pre[0]:
        pre = list(map(lambda x: -x, pre))
    post = []

    def getpost(root, tail, last_root):
        if root > tail:
            return
        i = root
        while i < tail and pre[i + 1] < pre[root]:
            if pre[i + 1] < last_root:
                return
            i += 1
        if i < tail and pre[i + 1] == pre[root]:
            i += 1
            if i < tail and pre[i + 1] < pre[root]:
                return
        getpost(root + 1, i, -99999)
        getpost(i + 1, tail, pre[root])
        post.append(pre[root])

    getpost(0, num - 1, -99999)
    if len(post) == num:
        print("YES")
        print(" ".join(list(map(lambda x: str(abs(x)), post))))
    else:
        print("NO")

