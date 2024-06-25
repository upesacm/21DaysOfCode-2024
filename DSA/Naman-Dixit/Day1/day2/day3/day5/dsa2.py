class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def are_identical(head1, head2):
    current1 = head1
    current2 = head2
    
    while current1 is not None and current2 is not None:
        if current1.data != current2.data:
            return False
        current1 = current1.next
        current2 = current2.next
    
    return current1 is None and current2 is None

def create_linked_list_from_input():
    head = None
    tail = None
    
    print("Enter integers to create a linked list (type 'done' to finish):")
    while True:
        user_input = input()
        if user_input.lower() == 'done':
            break
        try:
            data = int(user_input)
            new_node = Node(data)
            if head is None:
                head = new_node
                tail = new_node
            else:
                tail.next = new_node
                tail = new_node
        except ValueError:
            print("Invalid input, please enter an integer or 'done'.")
            
    return head

def main():
    print("Create the first linked list.")
    head1 = create_linked_list_from_input()
    
    print("Create the second linked list.")
    head2 = create_linked_list_from_input()
    
    if are_identical(head1, head2):
        print("The linked lists are identical.")
    else:
        print("The linked lists are not identical.")

if __name__ == "__main__":
    main()
