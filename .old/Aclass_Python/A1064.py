from math import floor, log2

def count_level(left_begin, right_end, level):
    if left_begin > right_end: return
    if left_begin == right_end:
        ans.append([nodes[left_begin], level])
        return
    num_nodes = right_end - left_begin + 1
    filled_nodes = pow(2, floor(log2(num_nodes + 1))) - 1
    root = left_begin + (filled_nodes - 1) // 2 + min(num_nodes - filled_nodes, (filled_nodes + 1) // 2)
    ans.append([nodes[root], level])
    count_level(left_begin, root - 1, level + 1)
    count_level(root + 1, right_end, level+1)

num = int(input())
nodes = sorted(list(map(int, input().split())))
ans = []
count_level(0, len(nodes) - 1, 0)
ans.sort(key=lambda x: x[1])
print(" ".join(list(map(lambda x: str(x[0]), ans))))

