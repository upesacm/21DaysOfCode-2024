def check_class_cancellation(threshold, arrival_times):
    on_time_students = [time for time in arrival_times if time <= 0]
    return "YES" if len(on_time_students) < threshold else "NO"

threshold = 4
arrival_times = [-2, -1, 0, 1, 2, 3]
print(check_class_cancellation(threshold, arrival_times))  
