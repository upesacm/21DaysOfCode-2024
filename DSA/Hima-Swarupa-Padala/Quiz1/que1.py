class SinglyLinkedListNode:
    def __init__(self, data):
        self.data = data
        self.next = None

def removeDuplicates(head):
    if not head or not head.next:
        return head
    current = head

    while current and current.next:
        if current.data == current.next.data:
            current.next = current.next.next
        else:
            current = current.next
    
    return head

def create_linked_list(elements):
    head = SinglyLinkedListNode(elements[0])
    current = head
    for element in elements[1:]:
        current.next = SinglyLinkedListNode(element)
        current = current.next
    return head

def display_linked_list(head):
    current = head
    while current:
        print(current.data, end=' ')
        current = current.next
    print()

elements = [1, 1, 2, 3, 3]
head = create_linked_list(elements)

head = removeDuplicates(head)

display_linked_list(head)  
