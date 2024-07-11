class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def intersection(head1, head2):
    def length_of_list(head):
        length = 0
        current = head
        while current:
            length += 1
            current = current.next
        return length
    
    len1 = length_of_list(head1)
    len2 = length_of_list(head2)
    
    diff = abs(len1 - len2)
    
    if len1 > len2:
        for i in range(diff):
            head1 = head1.next
    elif len2 > len1:
        for i in range(diff):
            head2 = head2.next
    
    while head1 is not head2:
        head1 = head1.next
        head2 = head2.next
    
    return head1

node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node1.next = node2
node2.next = node3

node4 = ListNode(4)
node5 = ListNode(5)
node6 = ListNode(6)
node4.next = node5
node5.next = node6

node6.next = node3

intersection_node = intersection(node1, node4)
if intersection_node:
    print(intersection_node.val) 
else:
    print("No intersection")
