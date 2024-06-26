class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Linkedlist:
    def __init__(self):
        self.head = None

    def print_list(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next

    def reverse_print(self, head):
        if head is None:
            return
        self.reverse_print(head.next)
        print(head.data, end=" ")


llist = Linkedlist()
llist.head = Node(1)
second = Node(2)
third = Node(3)
llist.head.next = second
second.next = third

print("The given linked list : ")
llist.print_list()
print("\nReversed Linked list : ")
llist.reverse_print(llist.head)
