n = int(input())
original = [-9999] + list(map(int, input().split()))
half_sorted = [-9999] + list(map(int, input().split()))

temp = 2
while temp <= n and half_sorted[temp - 1] <= half_sorted[temp]:
    temp += 1

if original[temp:] == half_sorted[temp:]:
    print("Insertion Sort")
    half_sorted = sorted(half_sorted[:temp + 1]) + half_sorted[temp + 1:]
else:
    print("Heap Sort")
    temp = n
    while temp > 2 and half_sorted[temp] >= half_sorted[1]:
        temp -= 1
    half_sorted[1], half_sorted[temp] = half_sorted[temp], half_sorted[1]
    i, j = 1, 2
    while j <= temp - 1:
        if j + 1 <= temp - 1 and half_sorted[j] < half_sorted[j + 1]:
            j = j + 1
        half_sorted[i], half_sorted[j] = half_sorted[j], half_sorted[i]
        i, j = j, j * 2

print(" ".join(map(str, half_sorted[1:])))