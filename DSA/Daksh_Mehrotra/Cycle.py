class ListNode:
  def __init__(self, x):
    self.val = x
    self.next = None
def has_cycle(head):
  """
  :type head: ListNode
  :rtype: str
  """
  slow = head
  fast = head
  while slow and fast and fast.next:
    slow = slow.next
    fast = fast.next.next
    if slow == fast:
      return "cycle"
  return "no cycle"
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = head.next  # Add cycle
print(has_cycle(head))
