def maxEqualHeight(stack1, stack2, stack3):
    height1 = sum(stack1)
    height2 = sum(stack2)
    height3 = sum(stack3)
    index1 = index2 = index3 = 0   
    while not (height1 == height2 == height3):
        if height1 >= height2 and height1 >= height3:
            height1 -= stack1[index1]
            index1 += 1
        elif height2 >= height1 and height2 >= height3:
            height2 -= stack2[index2]
            index2 += 1
        else:
            height3 -= stack3[index3]
            index3 += 1
    return height1
stack1 = [3, 2, 1, 1, 1]
stack2 = [4, 3, 2]
stack3 = [1, 1, 4, 1]
print(maxEqualHeight(stack1, stack2, stack3)) 
