class Queue:
    def __init__(self):
        self.s1 = []  # Stack for enqueue operation
        self.s2 = []  # Stack for dequeue operation

    def isEmpty(self):
        return len(self.s1) == 0 and len(self.s2) == 0

    def enqueue(self, data):
        self.s1.append(data)

    def dequeue(self):
        # Move elements from s1 to s2 if s2 is empty
        if self.isEmpty():
            raise Exception("Queue is empty") 
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())

        # Dequeue from s2
        return self.s2.pop()


# test case
q = Queue()
q.enqueue(1)
q.enqueue(2)
print("Dequeued:", q.dequeue())
print("Dequeued:", q.dequeue())
print("Queue is empty:", q.isEmpty())
