#You have three stacks of cylinders with varying heights. Remove cylinders from the top of the stacks so that all 
#stacks are of the same height, and return this maximum possible height.

def max_equal_heights(stack1, stack2, stack3):
    h1 = sum(stack1)
    h2 = sum(stack2)
    h3 = sum(stack3)

    p1 = p2 = p3 = 0

    while True:
        if h1 == h2 == h3:
            return h1
        if h1 >= h2 and h1 >= h3:
            h1 -= stack1[p1]
            p1 += 1 
        elif h2 >= h1 and h2 >= h3:
            h2 -= stack2[p2]
            p2 += 1
        else:
            h3 -= stack3[p3]
            p3 += 1

stack1 = [3,2,1,1,1]
stack2 = [4,3,2]
stack3 = [1,1,3,1]

print(max_equal_heights(stack1, stack2, stack3))
