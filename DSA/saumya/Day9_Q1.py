class MaxStack:
    def __init__(self):
        self.main_stack = []
        self.max_stack = []

    def push(self, x):
        self.main_stack.append(x)
        if not self.max_stack or x >= self.max_stack[-1]:
            self.max_stack.append(x)

    def pop(self):
        if not self.main_stack:
            raise Exception("Stack is empty")
        popped_element = self.main_stack.pop()
        if popped_element == self.max_stack[-1]:
            self.max_stack.pop()

    def get_max(self):
        if not self.max_stack:
            raise Exception("Stack is empty")
        return self.max_stack[-1]


# Test the MaxStack class
stack = MaxStack()
stack.push(1)
stack.push(2)
print(stack.get_max())  # Output: 2
stack.pop()
print(stack.get_max())  # Output: 1
