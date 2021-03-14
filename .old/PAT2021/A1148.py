n = int(input())
state = [0]
for i in range(n):
    state.append(int(input()))
def judge():
    for first in range(1, n):
        for second in range(first+1, n+1):
            temp = [1 for _ in range(n+1)]
            temp[first] = -1
            temp[second] = -1
            liar = []
            for i in range(1, n+1):
                if temp[abs(state[i])] != state[i] / abs(state[i]):
                    liar.append(i)
            if len(liar) == 2 and (first in liar or second in liar) and liar != [first, second]:
                print(first, second)
                return   
    else:
        print("No Solution")

judge()