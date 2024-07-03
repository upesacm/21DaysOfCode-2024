class QueueUsingStacks:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    def enqueue(self, item):
        self.stack1.append(item)
    def dequeue(self):
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        if self.stack2:
            return self.stack2.pop()
        else:
            raise IndexError("dequeue from empty queue")
    def is_empty(self):
        return not self.stack1 and not self.stack2
    def size(self):
        return len(self.stack1) + len(self.stack2)
queue = QueueUsingStacks()
queue.enqueue(1)
queue.enqueue(2)
print(queue.dequeue()) 
print(queue.dequeue()) 
queue.enqueue(3)
queue.enqueue(4)
print(queue.dequeue()) 
print(queue.dequeue()) 
