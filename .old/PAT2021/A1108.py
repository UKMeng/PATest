n = int(input())
array = input().split()
sum_of_number = 0
num_of_number = 0.0

def is_num(a):
    flag = 0
    count = 0
    for i in range(len(a)):
        if '0' <= a[i] <= '9' or (flag == 0 and a[i] == '.') or (i == 0 and a[i] == '-'):
            if a[i] == '.':
                flag = 1
            elif flag == 1:
                count += 1
                if count > 2: return False
        else:
            return False 
    temp = float(a)
    if -1000.0 <=temp <= 1000.0:
        return True
    else:
        return False
    
for i in range(n):
    if(is_num(array[i])):
        num_of_number += 1
        sum_of_number += float(array[i])
    else:
        print(f'ERROR: {array[i]} is not a legal number')
    
if num_of_number == 0:
    print('The average of 0 numbers is Undefined')
elif num_of_number == 1:
    print('The average of 1 number is %.2f' %(sum_of_number))
else:
    print('The average of %d numbers is %.2f' %(num_of_number, sum_of_number / num_of_number))