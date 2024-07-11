threshold = 3
arrival_times = [-1, -3, 4, 2]

on_time_count = 0

for time in arrival_times:
    if time <= 0:
        on_time_count += 1

if on_time_count < threshold:
    print("YES")
else:
    print("NO")
