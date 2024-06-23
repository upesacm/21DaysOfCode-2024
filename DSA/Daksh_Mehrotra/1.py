def is_class_cancelled(threshold, arrival_times):
    on_time_students = sum(1 for time in arrival_times if time <= 0)
    if on_time_students < threshold:
        return "YES"
    else:
        return "NO"
threshold = 3
arrival_times = [-1, -3, 4, 2]
print(is_class_cancelled(threshold, arrival_times)) 