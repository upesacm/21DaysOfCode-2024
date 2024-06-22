#Day2-Question1-
threshold = int(input("Enter the threshold number of students : "))
arrival_times = []
arrival_times = input("Enter the arrival times with the space : ").split(" ")
for i in range(len(arrival_times)):
    arrival_times[i] = int(arrival_times[i])

count = 0
for i in arrival_times:
    if i > 0:
      count += 1
    elif i == 0:
      pass
    else:
      count -= 1
if count >= 0:
  print("YES") 
else:
  print("NO")         
