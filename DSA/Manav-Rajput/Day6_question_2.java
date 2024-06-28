public class LinkedList3{
    // Define the Node class as a static nested class
    static class Node<T> {
        T data;
        Node<T> next;

        Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    // Print the linked list
    public static void print(Node<Integer> head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }
    public static int getLength(Node<Integer> head) {
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }

    // Find the merge point of two linked lists
    public static Integer findMergePoint(Node<Integer> head1, Node<Integer> head2) {
        int len1 = getLength(head1);
        int len2 = getLength(head2);

        while (len1 > len2) {
            head1 = head1.next;
            len1--;
        }
        while (len2 > len1) {
            head2 = head2.next;
            len2--;
        }


        while (head1 != null && head2 != null) {
            if (head1 == head2) {
                return head1.data;
            }
            head1 = head1.next;
            head2 = head2.next;
        }

        return null; // No merge point
    }

    public static void main(String[] args) {
        // Create the first linked list: 1 -> 2 -> 3
        Node<Integer> node1 = new Node<>(1);
        Node<Integer> node2 = new Node<>(2);
        Node<Integer> node3 = new Node<>(3);
        node1.next = node2;
        node2.next = node3;

        Node<Integer> head1 = node1;

        // Create the second linked list: 4 -> 5 -> 3
        Node<Integer> node4 = new Node<>(4);
        Node<Integer> node5 = new Node<>(5);
        node4.next = node5;
        node5.next = node3; // Merge point

        Node<Integer> head2 = node4;

        // Print the linked lists
        print(head1);
        print(head2); 

        // Find and print the merge point
        Integer mergePoint = findMergePoint(head1, head2);
        if (mergePoint != null) {
            System.out.println("Merge Point: " + mergePoint); // Expected Output: 3
        } else {
            System.out.println("No merge point");
        }
    }
}
