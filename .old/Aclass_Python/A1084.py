# s1 = input().upper()
# s2 = input().upper()
# temp = set()
# ans = []
# l1 = len(s1)
# l2 = len(s2)
# i = 0
# j = 0
# while i < l1 and j < l2:
#     if s1[i] != s2[j]:
#         if s1[i] not in temp:
#             temp.add(s1[i])
#             ans.append(s1[i])
#         i += 1 
#     else:
#         i += 1
#         j += 1
# while i < l1:
#     if s1[i] not in temp:
#         temp.add(s1[i])
#         ans.append(s1[i])
#     i += 1
# for i in ans:
#     print(i, end='')
a = input().upper()
b = input().upper()
c = set(a) - set(b)
for i in a:
    if i in c:
        print(i, end='')
        c.remove(i)
        