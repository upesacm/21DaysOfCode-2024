class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def print_reverse_stack(head):
    stack = []
    current = head
    while current:
        stack.append(current.value)
        current = current.next
    while stack:
        print(stack.pop(), end=' ')

def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for value in values[1:]:
        current.next = Node(value)
        current = current.next
    return head

# Taking user input
values = list(map(int, input("Enter the elements of the linked list separated by spaces: ").split()))

# Creating the linked list
head = create_linked_list(values)

# Printing the reversed list
print("Reversed list (stack method):")
print_reverse_stack(head)
print()
