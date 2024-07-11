#Day6-Question1-
class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def has_cycle(head):
    if not head:
        return "no cycle"
    
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            return "cycle"
    
    return "no cycle"

def create_linked_list(values, pos):
    if not values:
        return None
    
    head = ListNode(values[0])
    current = head
    nodes = [head]

    for value in values[1:]:
        new_node = ListNode(value)
        current.next = new_node
        current = new_node
        nodes.append(new_node)

    if pos != -1 and pos < len(values):
        current.next = nodes[pos]  # Create the cycle

    return head

values = list(map(int, input("Enter the node values (space-separated): ").split()))
pos = int(input("Enter the position to create a cycle (-1 for no cycle): "))

# Create the linked list
head = create_linked_list(values, pos)

# Check for cycle
result = has_cycle(head)
print(result)
