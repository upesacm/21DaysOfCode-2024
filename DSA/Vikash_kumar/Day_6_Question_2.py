#Day6-Question2-
class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def get_length(head):
    length = 0
    while head:
        length += 1
        head = head.next
    return length

def advance_by_n(head, n):
    while n > 0 and head:
        head = head.next
        n -= 1
    return head

def find_merge_point(head1, head2):
    len1 = get_length(head1)
    len2 = get_length(head2)
    
    if len1 > len2:
        head1 = advance_by_n(head1, len1 - len2)
    else:
        head2 = advance_by_n(head2, len2 - len1)
    
    while head1 and head2:
        if head1 == head2:
            return head1.value
        head1 = head1.next
        head2 = head2.next
    
    return None

def create_linked_list(values):
    if not values:
        return None
    
    head = ListNode(values[0])
    current = head

    for value in values[1:]:
        new_node = ListNode(value)
        current.next = new_node
        current = new_node

    return head

values1 = list(map(int, input("Enter the node values for the first linked list (space-separated): ").split()))
values2 = list(map(int, input("Enter the node values for the second linked list (space-separated): ").split()))

head1 = create_linked_list(values1)
head2 = create_linked_list(values2)

# Find merge point
result = find_merge_point(head1, head2)
print(result if result is not None else "No merge point")
