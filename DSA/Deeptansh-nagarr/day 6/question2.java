// Find Merge Point in Linked Lists Determine the node where two singly linked lists
// merge. Return the value of this node.
// Inputs:
// • Two singly linked lists.
// Output:
// • The value of the merging node.
// Example:
// # Linked list 1: 1 -> 2 -> 3
// # Linked list 2: 4 -> 5 -> 3
// # Output: 3

import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Main {
    static Node head1;
    static Node head2;
    static void insert(Node head, int data) {
        Node newNode = new Node(data);

        if (head == null) {
            if (head1 == null) {
                head1 = newNode;
            } else {
                head2 = newNode;
            }
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    static int findMergePoint(Node head1, Node head2) {
        int len1 = length(head1);
        int len2 = length(head2);
        Node temp1 = head1;
        Node temp2 = head2;
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) {
                temp1 = temp1.next;
            }
        } else {
            for (int i = 0; i < len2 - len1; i++) {
                temp2 = temp2.next;
            }
        }
        while (temp1 != temp2) {
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        return temp1.data;
    }

    static int length(Node head) {
        int len = 0;
        Node temp = head;
        while (temp != null) {
            len++;
            temp = temp.next;
        }
        return len;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of nodes in linked list 1: ");
        int n1 = scanner.nextInt();
        for (int i = 0; i < n1; i++) {
            System.out.print("Enter data for node " + (i + 1) + " in linked list 1: ");
            int data = scanner.nextInt();
            insert(head1, data);
        }

        System.out.print("Enter the number of nodes in linked list 2: ");
        int n2 = scanner.nextInt();
        for (int i = 0; i < n2; i++) {
            System.out.print("Enter data for node " + (i + 1) + " in linked list 2: ");
            int data = scanner.nextInt();
            insert(head2, data);
        }
        if (n1 > 1 && n2 > 1) {
            Node temp1 = head1;
            while (temp1.next != null) {
                temp1 = temp1.next;
            }
            Node temp2 = head2;
            while (temp2.next != null) {
                temp2 = temp2.next;
            }
            temp1.next = temp2.next;
        }
        System.out.println("Merge point: " + findMergePoint(head1, head2));
    }
}
