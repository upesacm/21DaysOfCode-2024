def max_height(stack1, stack2, stack3):
    height1, height2, height3 = sum(stack1), sum(stack2), sum(stack3)
    while True:
        if height1 == height2 == height3:
            return height1
        max_height = max(height1, height2, height3)
        if height1 == max_height:
            height1 = height1 - stack1.pop(0)
        if height2 == max_height:
           height2 = height2 - stack2.pop(0)
        if height3 == max_height:
            height3 = height3 - stack3.pop(0)

stack1 = [3, 2, 1, 1, 1]
stack2 = [4, 3, 2]
stack3 = [1, 1, 4, 1]
print(max_height(stack1, stack2, stack3))  