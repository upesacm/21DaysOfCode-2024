class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(data)

    def print_reverse(self):
        def _print_reverse(node):
            if node:
                _print_reverse(node.next)
                print(node.data, end=" ")

        _print_reverse(self.head)
        print()  

ll = LinkedList()
ll.append(1)
ll.append(2)
ll.append(3)

print("Linked list:")
current = ll.head
while current:
    print(current.data, end=" ")
    current = current.next
print()  

print("Output:")
ll.print_reverse()