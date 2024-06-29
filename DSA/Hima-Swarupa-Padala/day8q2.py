class StackUsingQueues:
    def __init__(self):
        self.q1 = [] 
        self.q2 = []  

    def push(self, val):
        self.q2.append(val)

        while self.q1:
            self.q2.append(self.q1.pop(0))
        self.q1, self.q2 = self.q2, self.q1

    def pop(self):
        if self.q1:
            return self.q1.pop(0)
        return None

    def top(self):
        if self.q1:
            return self.q1[0]
        return None

stack = StackUsingQueues()
stack.push(1)
stack.push(2)

print("Top element:", stack.top())  
print("Popped element:", stack.pop())  
print("Top element after pop:", stack.top())  
