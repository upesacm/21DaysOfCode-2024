// : Write a function to check if a singly linked list contains a cycle. Return "cycle" if a
// loop exists, otherwise return "no cycle".
// Inputs:
// • A singly linked list.
// Output:
// • "cycle" if there is a cycle, otherwise "no cycle".
// Example:
// # Linked list: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
// # Output: cycle

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
    static Node head;
    static void insert(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    static String hasCycle(Node head) {
        Node slow = head;
        Node fast = head;
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
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print("Enter data for node " + (i + 1) + ": ");
            int data = scanner.nextInt();
            insert(data);
        }

        if (n > 1) {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = head.next;
        }
        System.out.println(hasCycle(head));
    }
}
