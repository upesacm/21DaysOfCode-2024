class ListNode:
    def __init__(self,x):
        self.value=x
        self.next = None

def cycle(head):
    if not head or not head.next:
        return "No Cycle!"
    slow = head
    fast = head.next

    while fast and fast.next:
        if slow==fast:
            return "Cycle!!"
        slow = slow.next
        fast = fast.next.next
    return "No Cycle!"

node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node2

result = cycle(node1)
print(result)    
