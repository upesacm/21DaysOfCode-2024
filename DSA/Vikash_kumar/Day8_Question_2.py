Day8-Question2-
from collections import deque

class StackUsingQueues:
    def __init__(self):
        self.queue1 = deque()
        self.queue2 = deque()

    def push(self, x: int) -> None:
        self.queue1.append(x)

    def pop(self) -> int:
        if self.empty():
            return "Stack is empty"

        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        
        popped_element = self.queue1.popleft()
        
        self.queue1, self.queue2 = self.queue2, self.queue1
        
        return popped_element

    def top(self) -> int:
        if self.empty():
            return "Stack is empty"

        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
      
        top_element = self.queue1.popleft()
        
        self.queue2.append(top_element)
    
        self.queue1, self.queue2 = self.queue2, self.queue1
        
        return top_element

    def empty(self) -> bool:
        return not self.queue1 and not self.queue2

def user_input():
    stack = StackUsingQueues()
    
    while True:
        command = input("Enter command (push <value>, pop, top, quit): ").strip().split()
        
        if command[0] == "push":
            if len(command) != 2 or not command[1].isdigit():
                print("Invalid push command. Usage: push <value>")
                continue
            value = int(command[1])
            stack.push(value)
            print(f"Pushed {value} onto stack.")
        
        elif command[0] == "pop":
            result = stack.pop()
            print(f"Popped element: {result}")
        
        elif command[0] == "top":
            result = stack.top()
            print(f"Top element: {result}")
        
        elif command[0] == "quit":
            print("Exiting...")
            break
        
        else:
            print("Invalid command. Valid commands: push <value>, pop, top, quit.")

user_input()
