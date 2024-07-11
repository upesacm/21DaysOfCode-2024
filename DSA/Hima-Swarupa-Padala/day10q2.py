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
            raise IndexError("Queue is empty")

my_queue = QueueUsingStacks()
my_queue.enqueue(1)
my_queue.enqueue(2)
print(my_queue.dequeue())  
print(my_queue.dequeue())  

