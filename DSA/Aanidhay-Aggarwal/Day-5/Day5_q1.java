import java.util.Scanner;

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

    // Function to add a new node to the end of the list
    void addNode(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next!= null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    void printReverse() {
        printReverse(head);
    }

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
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            int data = scanner.nextInt();
            list.addNode(data);
        }

        System.out.print("Linked list: ");
        Node temp = list.head;
        while (temp!= null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");

        System.out.print("Output: ");
        list.printReverse();
        System.out.println();
    }
}
