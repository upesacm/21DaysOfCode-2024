import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int val) {
        this.data = val;
        this.next = null;
    }
}

public class Day6_Q2 {
    public static void insert(Node head, int data) {
        Node newNode = new Node(data);
        newNode.next = head.next;
        head.next = newNode;
    }

    public static Node findMergePoint(Node head1, Node head2) {
        if (head1 == null || head2 == null) return null;

        Node ptr1 = head1;
        Node ptr2 = head2;

        while (ptr1 != ptr2) {
            if (ptr1 == null) {
                ptr1 = head2;
            } else {
                ptr1 = ptr1.next;
            }

            if (ptr2 == null) {
                ptr2 = head1;
            } else {
                ptr2 = ptr2.next;
            }
        }

        return ptr1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Create first linked list: 1 -> 2 -> 3
        System.out.println("Enter the number of nodes in the first linked list:");
        int n1 = scanner.nextInt();
        System.out.println("Enter the values of the nodes for the first linked list:");
        Node head1 = new Node(scanner.nextInt());
        Node current1 = head1;
        for (int i = 1; i < n1; i++) {
            current1.next = new Node(scanner.nextInt());
            current1 = current1.next;
        }

        // Create second linked list: 4 -> 5 -> 3 (merge at node with value 3)
        System.out.println("Enter the number of nodes in the second linked list:");
        int n2 = scanner.nextInt();
        System.out.println("Enter the values of the nodes for the second linked list:");
        Node head2 = new Node(scanner.nextInt());
        Node current2 = head2;
        for (int i = 1; i < n2; i++) {
            current2.next = new Node(scanner.nextInt());
            current2 = current2.next;
        }

        // Manually setting up the merge point to simulate intersection
        System.out.println("Enter the value where the two lists merge:");
        int mergeVal = scanner.nextInt();
        Node mergeNode = head1;
        while (mergeNode != null && mergeNode.data != mergeVal) {
            mergeNode = mergeNode.next;
        }

        if (mergeNode != null) {
            current2.next = mergeNode;
        }

        // Finding merge point
        Node mergePoint = findMergePoint(head1, head2);
        if (mergePoint != null) {
            System.out.println("Merge Point: " + mergePoint.data);
        } else {
            System.out.println("No Merge Point");
        }

        scanner.close();
    }
}
