#Day5-Question2-
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

def are_identical(list1, list2):
    current1 = list1.head
    current2 = list2.head
    
    while current1 and current2:
        if current1.data != current2.data:
            return "different"
        current1 = current1.next
        current2 = current2.next
    
    if current1 is None and current2 is None:
        return "identical"
    else:
        return "different"

def create_linked_list():
    linked_list = LinkedList()
    elements = input("Enter the elements of the linked list separated by space: ").split()
    for element in elements:
        linked_list.append(int(element))
    return linked_list

# Create the first linked list from user input
print("Enter elements for the first linked list:")
linked_list1 = create_linked_list()

# Create the second linked list from user input
print("Enter elements for the second linked list:")
linked_list2 = create_linked_list()

# Check if the linked lists are identical
result = are_identical(linked_list1, linked_list2)
print(f"The linked lists are {result}.")
