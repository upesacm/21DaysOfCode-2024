public class LinkedList4 {
    static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        SinglyLinkedListNode(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static SinglyLinkedListNode removeDuplicates(SinglyLinkedListNode head) {
        if (head == null) {
            return head;
        }

        SinglyLinkedListNode current = head;

        while (current.next != null) {
            if (current.data == current.next.data) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }

        return head;
    }

    // Helper function to print the linked list
    public static void printLinkedList(SinglyLinkedListNode head) {
        SinglyLinkedListNode current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    // Helper function to create a linked list from an array
    public static SinglyLinkedListNode createLinkedList(int[] values) {
        if (values.length == 0) {
            return null;
        }

        SinglyLinkedListNode head = new SinglyLinkedListNode(values[0]);
        SinglyLinkedListNode current = head;
        for (int i = 1; i < values.length; i++) {
            current.next = new SinglyLinkedListNode(values[i]);
            current = current.next;
        }

        return head;
    }

    public static void main(String[] args) {
        int[] values = {1, 2, 2, 3, 4};
        SinglyLinkedListNode head = createLinkedList(values);
        head = removeDuplicates(head);
        printLinkedList(head);  // Output should be: 1 2 3 4
    }
}
