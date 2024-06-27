class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def getIntersectionNode(headA, headB):
    if not headA or not headB:
        return None
    pA, pB = headA, headB
    while pA is not pB:
        pA = pA.next if pA else headB
        pB = pB.next if pB else headA
    return pA
def create_linked_list(elements):
    head = ListNode(elements[0])
    current = head
    for element in elements[1:]:
        current.next = ListNode(element)
        current = current.next
    return head
common = create_linked_list([3])
headA = create_linked_list([1, 2])
headA.next.next = common
headB = create_linked_list([4, 5])
headB.next.next = common
intersection = getIntersectionNode(headA, headB)
print(f"The merge point value is: {intersection.val if intersection else 'No merge point found'}")
