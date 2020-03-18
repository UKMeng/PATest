MIN, MAX, unlock_id, lock_id = 9999999, -1, "signin", "signout"
num = int(input())

def convert(time):
    time = time.split(':')
    time = int(time[0]) * 3600 + int(time[1]) * 60 + int(time[2])
    return time

for _ in range(num):
    id, sign_in_time, sign_out_time = input().split()
    sign_in_time = convert(sign_in_time)
    sign_out_time = convert(sign_out_time)
    if sign_in_time < MIN:
        unlock_id = id
        MIN = sign_in_time
    if sign_out_time > MAX:
        lock_id = id
        MAX = sign_out_time

print(unlock_id, lock_id)