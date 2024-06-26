// Node class for the singly linked list
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    // Function to print the elements in reverse order
    void printReverse() {
        printReverse(head);
    }

    // Recursive function to print the elements in reverse order
    void printReverse(Node node) {
        if (node == null) {
            return;
        }
        printReverse(node.next);
        System.out.print(node.data + " ");
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.head = new Node(1);
        list.head.next = new Node(2);
        list.head.next.next = new Node(3);

        System.out.print("Linked list: ");
        Node temp = list.head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");

        System.out.print("Output: ");
        list.printReverse();
        System.out.println();
    }
}
