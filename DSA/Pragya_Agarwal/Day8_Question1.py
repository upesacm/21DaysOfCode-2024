def cylinder(s1,s2,s3):
    stack1 = sum(s1)
    stack2 = sum(s2)
    stack3 = sum(s3)
    while s1 and s2 and s3 :
        m=min(stack1,stack2,stack3)
        while stack1>m:
            stack1 -= s1.pop(0)
        while stack2>m:
            stack2 -= s2.pop(0)
        while stack3>m:
            stack3 -= s3.pop(0)
        if stack1==stack2==stack3:
            return stack1
s1 = [3, 2, 1, 1, 1]
s2 = [4, 3, 2]
s3 = [1, 1, 4, 1]

print(cylinder(s1,s2,s3))
