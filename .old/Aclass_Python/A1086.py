# n = int(input())  ### 不构建树，通过先序和中序来求后序，最后一个测试点答案错误，原因未知
# pre, inl = "", ""
# stack = []
# for i in range(2*n):
#     temp = input()
#     if temp == 'Pop':
#         inl = inl + stack[-1]
#         stack.pop()
#     else:
#         _, num = temp.split()
#         pre = pre + num
#         stack.append(num)

# def post(s1, s2, length):
#     pos = 0
#     for i in range(length):
#         if s2[i] == s1[0]:
#             pos = i
#             break
#     l1 = pos
#     l2 = length - pos - 1
#     a1 = s1[1:pos+1]
#     a2 = s2[0:pos]
#     #print(a1, a2)
#     if l1 > 1:
#         ans1 = post(a1, a2, l1)
#     else: ans1 = a1
#     b1 = s1[pos+1:length]
#     b2 = s2[pos+1:length]
#     #print(b1, b2)
#     if l2 > 1:
#         ans2 = post(b1, b2, l2)
#     else: ans2 = b1
#     return ans1 + ans2 + s1[0]

# ans = post(pre, inl, n)
# print(" ".join(ans))

class Node:         ### 构建树来求后序
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

num = int(input())
stack = []
father = None
for i in range(2 * num):
    info = input()
    if info == "Pop":
        father = stack[-1]
        stack.pop()
    else:
        if not father:
            stack.append(Node(int(info.split()[1])))
            root = stack[0]
        elif not father.left:
            stack.append(Node(int(info.split()[1])))
            father.left = stack[-1]
        else:
            stack.append(Node(int(info.split()[1])))
            father.right = stack[-1]
        father = stack[-1]

ans = []
def post(node):
    if node.left:
        post(node.left)
    if node.right:
        post(node.right)
    ans.append(node.val)

post(root)
print(" ".join(list(map(str, ans))))