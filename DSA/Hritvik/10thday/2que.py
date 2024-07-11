def enqueue(stack1,item):
    stack1.append(item)

def dequeue(stack1, stack2):
    if not stack2:
        while stack1:
            stack2.append(stack1.pop())
    if not stack2:
        return None  
    return stack2.pop()

if __name__ == "__main__":
    stack1 = []
    stack2 = []
    
    enqueue(stack1, 1)
    enqueue(stack1, 2)
    
    print(dequeue(stack1, stack2))  
    print(dequeue(stack1, stack2))   
