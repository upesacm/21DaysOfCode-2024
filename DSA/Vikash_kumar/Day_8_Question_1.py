#Day8-Question1-
def max_equal_stack_height(stack1, stack2, stack3):
    height1 = sum(stack1)
    height2 = sum(stack2)
    height3 = sum(stack3)
    
    index1 = 0
    index2 = 0
    index3 = 0
    
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

def get_stack_input(stack_num):
    return list(map(int, input(f"Enter the heights of cylinders in stack {stack_num} separated by spaces: ").split()))

stack1 = get_stack_input(1)
stack2 = get_stack_input(2)
stack3 = get_stack_input(3)

max_height = max_equal_stack_height(stack1, stack2, stack3)

print(f"The maximum possible height where all stacks are equal is: {max_height}")
