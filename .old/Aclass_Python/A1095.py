# 运行超时
record_num, query_num = map(int, input().split())
records = []
for _ in range(record_num):
    record_info = list(input().split())
    id = record_info[0]
    hour, minute, second = record_info[1].split(":")
    time = int(hour) * 3600 + int(minute) * 60 + int(second)
    status = 1 if record_info[2] == 'in' else -1
    records.append((id, time, status))

records.sort(key=lambda x: (x[0], x[1]))

max_time, max_id, pre, clean_records, park_time = 0, [], records[0][0], [], 0
for i in range(record_num - 1):
    if records[i][0] == records[i + 1][0] and records[i][2] == 1 and records[i + 1][2] == -1:
        clean_records.append(records[i])
        clean_records.append(records[i+1])
        if records[i][0] != pre:
            if max_time < park_time:
                max_time = park_time
                max_id = [pre]
            elif max_time == park_time:
                max_id.append(pre)
            pre = records[i][0]
            park_time = 0
        park_time += (records[i + 1][1] - records[i][1])

if max_time < park_time:
    max_time = park_time
    max_id = [pre]
elif max_time == park_time:
    max_id.append(pre)

clean_records.sort(key=lambda x:x[1])

time_index, count = 0, 0
for _ in range(query_num):
    hour, minute, second = list(map(int, input().split(":")))
    query_time = hour * 3600 + minute * 60 + second
    while time_index < len(clean_records) and clean_records[time_index][1] <= query_time:
        count += clean_records[time_index][2]
        time_index += 1
    print(count)

for i in max_id:
    print(i, end=" ")
print("%02d:%02d:%02d" % (max_time // 3600, max_time % 3600 // 60, max_time % 60))
            
    