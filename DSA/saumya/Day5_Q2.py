class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def compare_lists(head1, head2):
 #       head1: The head node of the first linked list.
  #      head2: The head node of the second linked list.

   # returns "identical" if the lists are the same, otherwise "different".   
    while head1 and head2:
        if head1.data != head2.data:
            return "different"
        head1 = head1.next
        head2 = head2.next

    # If one list is longer than the other, they are different.
    if head1 or head2:
        return "different"

    return "identical"

head1 = Node(1)
head1.next = Node(2)
head1.next.next = Node(3)

head2 = Node(1)
head2.next = Node(2)
head2.next.next = Node(3)

print(compare_lists(head1, head2))   # Output: identical

head3 = Node(1)
head3.next = Node(2)
head3.next.next = Node(4)

print(compare_lists(head1, head3))    # Output: different
