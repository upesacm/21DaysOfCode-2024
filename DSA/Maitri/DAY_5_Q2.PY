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

def are_identical(head1, head2):
    while head1 is not None and head2 is not None:
        if head1.value != head2.value:
            return "different"
        head1 = head1.next
        head2 = head2.next
    if head1 is None and head2 is None:
        return "identical"
    else:
        return "different"

# Taking user input for the first linked list
values1 = list(map(int, input("Enter the elements of the first linked list separated by spaces: ").split()))
head1 = create_linked_list(values1)

# Taking user input for the second linked list
values2 = list(map(int, input("Enter the elements of the second linked list separated by spaces: ").split()))
head2 = create_linked_list(values2)

# Comparing the linked lists
result = are_identical(head1, head2)
print(result)
