import heapq

class PriorityQueue:
    def __init__(self):
        self.heap = []
    
    def insert(self, item):
        heapq.heappush(self.heap, item)
    
    def extract_min(self):
        if self.heap:
            return heapq.heappop(self.heap)
        else:
            return None  # or raise an exception if preferred

# Example usage:
priority_queue = PriorityQueue()
priority_queue.insert(4)
priority_queue.insert(2)

print(priority_queue.extract_min())  # Output: 2
print(priority_queue.extract_min())  # Output: 4
print(priority_queue.extract_min())  # Output: None (or raise an exception)
