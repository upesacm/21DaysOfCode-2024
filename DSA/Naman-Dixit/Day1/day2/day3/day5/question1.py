class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def print_reverse_using_stack(head):
    stack = []
    current = head
    
    while current:
        stack.append(current.data)
        current = current.next
    
    while stack:
        print(stack.pop(), end=' ')
    print()

def print_reverse_using_recursion(head):
    if head is None:
        return
    
    print_reverse_using_recursion(head.next)
    print(head.data, end=' ')
    print()

def create_linked_list_from_input():
    head = None
    tail = None
    
    while True:
        try:
            data = int(input("Enter an integer (or type 'done' to finish): "))
            new_node = Node(data)
            
            if head is None:
                head = new_node
                tail = new_node
            else:
                tail.next = new_node
                tail = new_node
                
        except ValueError:
            break
            
    return head

def main():
    print("Please enter integers to create a linked list.")
    head = create_linked_list_from_input()
    
    print("\nLinked list in reverse order using stack:")
    print_reverse_using_stack(head)
    
    print("\nLinked list in reverse order using recursion:")
    print_reverse_using_recursion(head)

if __name__ == "__main__":
    main()
