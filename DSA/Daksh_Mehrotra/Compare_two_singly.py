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

def are_identical(list1, list2):
    current1 = list1.head
    current2 = list2.head
    while current1 is not None and current2 is not None:
        if current1.data != current2.data:
            return "different"
        current1 = current1.next
        current2 = current2.next
    if current1 is None and current2 is None:
        return "identical"
    else:
        return "different"
if __name__ == "__main__":
    llist1 = LinkedList()
    llist2 = LinkedList()
    llist1.push(3)
    llist1.push(2)

    llist1.push(1)

    llist2.push(3)
    llist2.push(2)
    llist2.push(1)
    
    result = are_identical(llist1, llist2)
    print("The lists are:", result)
    llist3 = LinkedList()
    llist3.push(4)
    llist3.push(2)
    llist3.push(1)
    result = are_identical(llist1, llist3)
    print("The lists are:", result)
