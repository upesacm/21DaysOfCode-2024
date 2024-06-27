class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

def check_cycle(head):

  slow, fast = head, head
  while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
    if slow == fast:
      return "cycle"
  return "no cycle"

# Test cases
# Creating a cycle
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = head.next

result = check_cycle(head)
print(result)  # Output: cycle

# Creating a non-cycle
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)

result = check_cycle(head)
print(result)  # Output: no cycle
