class Priority_Queue:
    def __init__(self):
        self.queue = []

    def insert(self, item):
        self.queue.append(item)
        self.queue.sort()

    def extract_min(self):
        if len(self.queue) == 0:
            return None
        return self.queue.pop(0)

priority_queue = Priority_Queue()
priority_queue.insert(4)
priority_queue.insert(2)
print(priority_queue.extract_min())  # Output: 2
print(priority_queue.extract_min())  # Output: 4
