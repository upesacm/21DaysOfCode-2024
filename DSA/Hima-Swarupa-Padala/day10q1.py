from queue import Queue

def reverse_queue(queue):
    if not queue.empty():
        front = queue.get()
        reverse_queue(queue)
        queue.put(front)

my_queue = Queue()
my_queue.put(1)
my_queue.put(2)
my_queue.put(3)

print("queue:", list(my_queue.queue))
reverse_queue(my_queue)
print("Output:", list(my_queue.queue))
