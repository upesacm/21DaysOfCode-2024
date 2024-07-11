class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, x):
        self.queue.append(x)

    def dequeue(self):
        if not self.is_empty():
            return self.queue.pop(0)
        return None

    def is_empty(self):
        return len(self.queue) == 0

    def size(self):
        return len(self.queue)

class Stack:
    def __init__(self):
        self.q1 = Queue()
        self.q2 = Queue()

    def push(self, x):
        self.q2.enqueue(x)
        while not self.q1.is_empty():
            self.q2.enqueue(self.q1.dequeue())
        self.q1, self.q2 = self.q2, self.q1

    def pop(self):
        if not self.q1.is_empty():
            return self.q1.dequeue()
        return None

    def top(self):
        if not self.q1.is_empty():
            return self.q1.queue[0]
        return None

#TEST CASE
stack = Stack()
stack.push(1)
stack.push(2)
print(stack.top())  # Output: 2
print(stack.pop())  # Output: 2
print(stack.top())  # Output: 1
