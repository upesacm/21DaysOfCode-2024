class MaxStack:
    def __init__(self):
        self.stack = [] 
        self.max_stack = []

    def push(self, val):
        self.stack.append(val)
        if not self.max_stack or val >= self.max_stack[-1]:
            self.max_stack.append(val)

    def pop(self):
        if self.stack:
            popped = self.stack.pop()
            if popped == self.max_stack[-1]:
                self.max_stack.pop()
            return popped
        else:
            return None

    def get_max(self):
        return self.max_stack[-1] if self.max_stack else None

stack = MaxStack()
stack.push(1)
stack.push(2)
print(stack.get_max())
stack.pop()
print(stack.get_max())
