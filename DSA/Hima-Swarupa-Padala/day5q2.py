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

    def compare_lists(self, list2):
        current1 = self.head
        current2 = list2.head

        while current1 and current2:
            if current1.data != current2.data:
                return "different"
            current1 = current1.next
            current2 = current2.next

        if current1 or current2:
            return "different"

        return "identical"

l1 = LinkedList()
l1.append(1)
l1.append(2)
l1.append(3)

l2 = LinkedList()
l2.append(1)
l2.append(2)
l2.append(3)

l3 = LinkedList()
l3.append(1)
l3.append(5)
l3.append(4)

print(l1.compare_lists(l2))  
print(l1.compare_lists(l3)) 
