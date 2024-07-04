from queue import Queue

def reverse_queue(q):
    if q.empty():
        return
    front = q.get()
    reverse_queue(q)
    q.put(front)
def print_queue(q):
    size = q.qsize()
    for _ in range(size):
        elem = q.get()
        print(elem, end=' ')
        q.put(elem)
    print()
queue = Queue()
queue.put(1)
queue.put(2)
queue.put(3)

print("Original queue:")
print_queue(queue)
reverse_queue(queue)
print("Reversed queue:")
print_queue(queue)
