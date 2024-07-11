class SLL:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

def removeduplicates(head):

    current = head
    while current is not None and current.next is not None:
        if current.data == current.next.data:
            new_next = current.next.next
            del current.next
            current.next = new_next
        else:
            current = current.next
    return head
