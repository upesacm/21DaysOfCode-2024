def threshold_count(arrival_times, threshold):
    count = 0
    n = len(arrival_times)
    for i in range(n):
        if arrival_times[i] < threshold:
            count += 1
    return count

# Take user inputs
arrival_times = list(map(int, input("Enter the student numbers separated by spaces: ").split()))
threshold_student = int(input("Enter the threshold number of students: "))

result = threshold_count(arrival_times, threshold_student)

if result >= threshold_student:
    print("NO")
else:
    print("YES")

