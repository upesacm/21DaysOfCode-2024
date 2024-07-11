class PriorityQueue:
    def __init__(self):
        self.heap = []

    def _parent(self, index):
        return (index - 1) // 2

    def _left_child(self, index):
        return 2 * index + 1

    def _right_child(self, index):
        return 2 * index + 2

    def _heapify_up(self, index):
        parent = self._parent(index)
        if index > 0 and self.heap[index] < self.heap[parent]:
            self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
            self._heapify_up(parent)

    def _heapify_down(self, index):
        smallest = index
        left = self._left_child(index)
        right = self._right_child(index)

        if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
            smallest = left
        if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
            smallest = right
        if smallest != index:
            self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
            self._heapify_down(smallest)

    def insert(self, element):
        self.heap.append(element)
        self._heapify_up(len(self.heap) - 1)

    def extract_min(self):
        if not self.heap:
            raise IndexError("extract_min from empty priority queue")
        min_element = self.heap[0]
        last_element = self.heap.pop()
        if self.heap:
            self.heap[0] = last_element
            self._heapify_down(0)
        return min_element

    def peek_min(self):
        if not self.heap:
            raise IndexError("peek_min from empty priority queue")
        return self.heap[0]

    def is_empty(self):
        return len(self.heap) == 0

priority_queue = PriorityQueue()
priority_queue.insert(4)
priority_queue.insert(2)

print(priority_queue.extract_min())  
print(priority_queue.extract_min())  



