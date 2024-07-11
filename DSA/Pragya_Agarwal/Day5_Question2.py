class ListNode:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next
        
def compare(head1, head2):
    current1 = head1
    current2 = head2
    
    while current1 is not None and current2 is not None:
        if current1.value != current2.value:
            return "Different"
        current1 = current1.next
        current2 = current2.next
    if current1 is None and current2 is None:
        return "Identical"
    else:
        return "Different"
    
def main():
    head1 = ListNode(1)
    head1.next = ListNode(2)
    head1.next.next = ListNode(3)
    
    head2 = ListNode(1)
    head2.next = ListNode(2)
    head2.next.next = ListNode(3)
    
    result = compare(head1, head2)
    print("Output:", result)  

main()
