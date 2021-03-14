num = int(input())
post = list(map(int, input().split()))
inorder = list(map(int, input().split()))
ans = []

def levelOrder(postroot, start_in, end_in, level):
    if start_in > end_in: return
    root_in = inorder.index(post[postroot])
    ans.append((level, post[postroot]))
    levelOrder(postroot - 1 - end_in + root_in,start_in, root_in - 1,level + 1)
    levelOrder(postroot - 1, root_in + 1, end_in, level + 1)

levelOrder(num - 1, 0, num - 1, 1)
ans.sort(key=lambda x:x[0])
print(" ".join(map(lambda x:str(x[1]), ans)))