class MaxStack:
    def __init__(self):
        self.stack = []  
        self.max_stack = [] 
    def push(self, value: int):
        self.stack.append(value)
        if not self.max_stack or value >= self.max_stack[-1]:
            self.max_stack.append(value)
    def pop(self):
        if self.stack:
            value = self.stack.pop()
            if value == self.max_stack[-1]:
                self.max_stack.pop()
    def get_max(self):
        if self.max_stack:
            return self.max_stack[-1]
        return None
stack = MaxStack()
stack.push(1)
stack.push(2)
print(stack.get_max())  
stack.pop()
print(stack.get_max())
