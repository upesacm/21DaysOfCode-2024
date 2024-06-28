class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for value in values[1:]:
        current.next = Node(value)
        current = current.next
    return head

def create_cycle(head, pos):
    if pos == -1:
        return head
    cycle_node = None
    current = head
    count = 0
    while current.next:
        if count == pos:
            cycle_node = current
        current = current.next
        count += 1
    current.next = cycle_node
    return head

def has_cycle(head):
    if not head or not head.next:
        return "no cycle"
    
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return "cycle"
    
    return "no cycle"

def print_linked_list(head):
    current = head
    while current:
        print(current.value, end=" -> ")
        current = current.next
    print("None")

# Take user input to create the linked list
values = list(map(int, input("Enter the elements of the linked list separated by spaces: ").split()))
head = create_linked_list(values)

# Optional: To create a cycle manually based on user input
cycle_pos = int(input("Enter the position to create a cycle (-1 for no cycle): "))
head = create_cycle(head, cycle_pos)

# Print the linked list (for demonstration, it won't terminate if there's a cycle)
print("Linked List (Note: If there's a cycle, this will print indefinitely):")
print_linked_list(head)

# Check if the linked list has a cycle
result = has_cycle(head)
print("Cycle Check Result:", result)

