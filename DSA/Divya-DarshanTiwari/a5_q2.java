import java.util.Scanner;

class Node {
    int data;
    Node next;

    static void createList(Node head, int n, Scanner sc) {
        System.out.print("Enter data for element 1: ");
        head.data = sc.nextInt();
        head.next = null;
        Node temp = head;
        for (int i = 1; i < n; i++) {
            Node newNode = new Node();
            System.out.print("Enter data for element " + (i + 1) + ": ");
            newNode.data = sc.nextInt();
            newNode.next = null;
            temp.next = newNode;
            temp = newNode;
        }
    }

    static String compareList(Node head1, Node head2) {
        while (head1 != null && head2 != null) {
            if (head1.data != head2.data) {
                return "different";
            }
            head1 = head1.next;
            head2 = head2.next;
        }
        return "identical";
    }

    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }
}

public class a5_q2 {
    public static void main(String[] args) {
        Node head1 = new Node();
        Node head2 = new Node();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements for list 1: ");
        int n1 = sc.nextInt();
        Node.createList(head1, n1, sc);
        System.out.print("Enter number of elements for list 2: ");
        int n2 = sc.nextInt();
        Node.createList(head2, n2, sc);
        if (n1 != n2) {
            System.out.println("different");
        } else {
            System.out.println(Node.compareList(head1, head2));
        }
        sc.close();
    }
}
