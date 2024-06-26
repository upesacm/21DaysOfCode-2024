#Day5-Question1-
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node

    def print_reverse(self):
        stack = []
        current = self.head
        while current:
            stack.append(current.data)
            current = current.next
        while stack:
            print(stack.pop(), end=" ")

def create_linked_list():
    linked_list = LinkedList()
    elements = input("Enter the elements of the linked list separated by space: ").split()
    for element in elements:
        linked_list.append(int(element))
    return linked_list

linked_list = create_linked_list()

print("The elements of the linked list in reverse order are:")
linked_list.print_reverse()
