def should_class_be_cancelled(arrival_times, threshold):
    student_on_time = 0
    for time in arrival_times:
        if time <= 0:
            student_on_time += 1
    if student_on_time < threshold:
        print("YES")
    else:
        print("NO")

# Test case - 1
case1 = [-1, -2, -5, 3]
threshold = 2
print("Output from test case 1")
should_class_be_cancelled(case1, threshold)

# Test case - 2
case2 = [-1, -3, 0, 8, 4, 2]
threshold = 3
print("Output from test case 2")
should_class_be_cancelled(case2, threshold)

# Test case - 3
case3 = [-1, -3, 0, -8, 6, 2]
threshold = 6
print("Output from test case 3")
should_class_be_cancelled(case3, threshold)

