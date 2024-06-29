def equal_height(stack1, stack2, stack3):
    total1, total2, total3 = sum(stack1), sum(stack2), sum(stack3)
    while total1 != total2 or total2 != total3:
        if total1 >= total2 and total1 >= total3:
            total1 -= stack1.pop(0)
        elif total2 >= total1 and total2 >= total3:
            total2 -= stack2.pop(0)
        else:
            total3 -= stack3.pop(0)
    return total1
  
#Test case
stack1 = [3, 2, 1, 1, 1]
stack2 = [4, 3, 2]
stack3 = [1, 1, 4, 1]

print(equal_height(stack1, stack2, stack3))  # Output: 5
