class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def get_intersection_node(head1, head2):
    while head2 is not None:
        temp = head1
        while temp is not None:
            if temp is head2:
                return head2.data
            temp = temp.next
        head2 = head2.next
    return -1

# test case
head1 = Node(1)
head1.next = Node(2)
head1.next.next = Node(3)

head2 = Node(4)
head2.next = Node(5)
head2.next.next = head1.next.next

print(get_intersection_node(head1, head2))

