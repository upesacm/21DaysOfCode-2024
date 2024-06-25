import java.util.Scanner;

class Node {
    int data;
    Node next;

    void createList(Node head, int n) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter data for element 1 : ");
        head.data = scanner.nextInt();
        head.next = null;
        Node temp = head;
        for (int i = 1; i < n; i++) {
            Node newNode = new Node();
            System.out.print("Enter data for element " + (i + 1) + " : ");
            newNode.data = scanner.nextInt();
            newNode.next = null;
            temp.next = newNode;
            temp = newNode;
        }
        scanner.close();
    }

    void printList(Node head) {
        while (head!= null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    void revese(Node head){
        Node prev = new Node();
        Node next = new Node();
        Node current = new Node();
        current = head;
        prev = head;
        next = current.next;
        prev.next = null;
        while(next!=null){
            head=next;
            current=head;
            next = current.next;
            current.next=prev;
            prev = current;
        }
        head.printList(head);
    }
}

public class a5_q1 {
    public static void main(String[] args) {
        Node head = new Node();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of elements : ");
        int n = scanner.nextInt();
        head.createList(head, n);
        head.revese(head);

        scanner.close();
    }
}