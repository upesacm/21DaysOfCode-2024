class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

def find_merge_point(head1, head2):
    node_dict = {}
    temp = head1
    while temp:
        node_dict[temp] = True
        temp = temp.next

    temp = head2
    while temp:
        if temp in node_dict:
            return temp.val
        temp = temp.next

    return None

a1 = ListNode(1)
a1.next = ListNode(2)
a1.next.next = ListNode(3)

a2 = ListNode(4)
a2.next = ListNode(5)
a2.next.next = a1.next.next  

merge_point = find_merge_point(a1, a2)
print(merge_point)  