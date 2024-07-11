class ListNode:
    def __init__(self,value,next=None):
        self.value = value
        self.next = next 
def print_reverse(head):
    stack = []
    current = head

    while current:
        stack.append(current.value)
        current = current.next
    while stack:
        print(stack.pop(),end=" ") 

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    
    print("Linked list:",end=" ")
    print_reverse(head)

main()
