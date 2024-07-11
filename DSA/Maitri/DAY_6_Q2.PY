class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for value in values[1:]:
        current.next = Node(value)
        current = current.next
    return head

def print_linked_list(head):
    current = head
    while current:
        print(current.value, end=" -> " if current.next else "\n")
        current = current.next

def find_merge_point(head1, head2):
    nodes_set = set()
    current1 = head1
    while current1:
        nodes_set.add(current1)
        current1 = current1.next

    current2 = head2
    while current2:
        if current2 in nodes_set:
            return current2.value
        current2 = current2.next

    return None


values1 = list(map(int, input("Enter the elements of the first linked list separated by spaces: ").split()))
values2 = list(map(int, input("Enter the elements of the second linked list separated by spaces: ").split()))

head1 = create_linked_list(values1)
head2 = create_linked_list(values2)

merge_point_value = find_merge_point(head1, head2)
if merge_point_value:
    print("The merge point value is:", merge_point_value)
else:
    print("No merge point found.")
