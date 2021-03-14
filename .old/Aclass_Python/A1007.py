length = int(input())
nums = list(map(int, input().split()))
front, end, largest, temp, temp_front = 0, length - 1, -1, 0, 0
# 动态规划
for i, j in enumerate(nums):
    temp += j
    if temp < 0:
        temp = 0
        temp_front = i + 1
    elif temp > largest:
        largest = temp
        front = temp_front
        end = i

if largest == -1:
    largest = 0
print(largest, nums[front], nums[end])
