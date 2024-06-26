class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class LinkedList:
    def __init__(self):
        self.head = None
    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node
    def print_reverse(self):
        stack = []
        current = self.head
        while current:
            stack.append(current.data)
            current = current.next
        while stack:
            print(stack.pop(), end=' ')
            print()
if __name__ == "__main__":
    llist = LinkedList()
    llist.push(3)
    llist.push(2)
    llist.push(1)
    print("Original Linked list: 1 -> 2 -> 3")
    print("Reversed order: ", end='')
    llist.print_reverse()
