public class LinkedList1 {
    // Define the Node class as a static nested class
    static class Node<T> {
        T data;
        Node<T> next;

        Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    //  print the linked list
    public static void print(Node<Integer> head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

  
    // compare two linked lists
    public static String areIdentical(Node<Integer> head1, Node<Integer> head2) {
        while (head1 != null && head2 != null) {
            if (!head1.data.equals(head2.data)) {
                return "different";
            }
            head1 = head1.next;
            head2 = head2.next;
        }
        if (head1 == null && head2 == null) {
            return "identical";
        }
        return "different";
    }

    public static void main(String[] args) {
        Node<Integer> node1 = new Node<>(30);
        Node<Integer> node2 = new Node<>(40);
        Node<Integer> node3 = new Node<>(60);
        Node<Integer> head1 = node1;
        node1.next = node2;
        node2.next = node3;

        Node<Integer> node4 = new Node<>(30);
        Node<Integer> node5 = new Node<>(40);
        Node<Integer> node6 = new Node<>(60);
        Node<Integer> head2 = node4;
        node4.next = node5;
        node5.next = node6;

        // Print the linked lists
        print(head1);
        print(head2);

        // Check if the linked lists are identical
        System.out.println(areIdentical(head1, head2));
    }
}
