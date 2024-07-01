#Day-10-Question1-
from collections import deque

def reverse_queue(queue):
    if len(queue) == 0:
        return
    
    front = queue.popleft()
    
    reverse_queue(queue)
    
    queue.append(front)

user_input = input("Enter the elements of the queue separated by spaces: ")
queue_list = list(map(int, user_input.split()))
queue = deque(queue_list)

print("Original queue:", list(queue))
reverse_queue(queue)
print("Reversed queue:", list(queue))
