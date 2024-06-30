class MaxStack:
    def __init__(self):
        self.stack = []
        self.max_value = None
    def push(self, x: int)->None:
        if not self.stack:
            self.max_value= x
        else:
            self.max_value =max(x, self.max_value)
        self.stack.append((x, self.max_value))
    def pop(self)->None:
        if self.stack:
            self.stack.pop()
            if self.stack:
                self.max_value =self.stack[-1][1]
            else:
                self.max_value= None
    def get_max(self)->int:
        if self.stack:
            return self.stack[-1][1]
        return None

stack = MaxStack()
stack.push(1)
stack.push(2)
print(stack.get_max())  
stack.pop()
print(stack.get_max())  
