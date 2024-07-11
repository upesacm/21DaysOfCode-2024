class PriorityQueue:
    def __init__(self):
        self.heap = []
    def insert(self, item):
        self.heap.append(item)
        self._bubble_up(len(self.heap) - 1)
    def extract_min(self):
        if not self.heap:
            raise IndexError("extract_min() called on empty priority queue")
        self._swap(0, len(self.heap) - 1)
        min_item = self.heap.pop()
        self._bubble_down(0)
        return min_item

    def _bubble_up(self, index):
        parent_index = (index - 1) // 2
        if index > 0 and self.heap[index] < self.heap[parent_index]:
            self._swap(index, parent_index)
            self._bubble_up(parent_index)

    def _bubble_down(self, index):
        child_index = 2 * index + 1
        if child_index < len(self.heap):
            right_child = child_index + 1
            if right_child < len(self.heap) and self.heap[right_child] < self.heap[child_index]:
                child_index = right_child
            if self.heap[index] > self.heap[child_index]:
                self._swap(index, child_index)
                self._bubble_down(child_index)

    def _swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

# Example usage:
priority_queue = PriorityQueue()
priority_queue.insert(4)
priority_queue.insert(2)
print(priority_queue.extract_min())  
print(priority_queue.extract_min()) 
