public class LinkedList2 {
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

    // Check if a singly linked list contains a cycle
    public static String hasCycle(Node<Integer> head) {
        if (head == null) {
            return "no cycle";
        }
        Node<Integer> slow = head;
        Node<Integer> fast = head;
        
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            
            if (slow == fast) {
                return "cycle";
            }
        }
        return "no cycle";
    }

    public static void main(String[] args) {
        Node<Integer> node1 = new Node<>(1);
        Node<Integer> node2 = new Node<>(2);
        Node<Integer> node3 = new Node<>(3);
        Node<Integer> node4 = new Node<>(4);

        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node2; // Creates a cycle

        Node<Integer> head = node1;
        // Check if the linked list has a cycle
        System.out.println(hasCycle(head)); // Expected: cycle
    }
}
