node_num, nonleaf_num = map(int, input().split())
node_info = [[] for _ in range(node_num + 1)]
if node_num == 1: print("1")
else:
    for _ in range(nonleaf_num):
        a = list(map(int, input().split()))
        node_info[a[0]] = a[2:]
    # BFS
    level, que = [0], [1]
    while que:
        length, temp_num = len(que), 0
        for _ in range(length):
            father = que.pop()
            for son in node_info[father]:
                if not node_info[son]: temp_num += 1
                else: que.insert(0, son)
        level.append(temp_num)
    # join只能str？ 
    print(" ".join(map(str, level)))