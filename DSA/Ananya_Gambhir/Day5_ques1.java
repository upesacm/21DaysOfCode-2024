import java.util.*;
public class Day5_ques1 {
    Node head;
    static class Node {
        int data;
        Node next;
        Node(int d) {
            data=d;
            next=null;
        }
    }
    Node reverse(Node node) {
        Node prev = null;
        Node current = node;
        Node next = null;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        node = prev;
        return node;
    }
    void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }
    void insert(int data) {
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
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Day5_ques1 list = new Day5_ques1();

        System.out.println("Enter the number of elements :");
        int n = scanner.nextInt();

        System.out.println("Enter the elements of the linked list:");
        for (int i = 0; i < n; i++) {
            int element = scanner.nextInt();
            list.insert(element);
        }

        System.out.println("Given linked list:");
        list.printList(list.head);

        list.head = list.reverse(list.head);

        System.out.println("Reversed linked list:");
        list.printList(list.head);

        scanner.close();
    }
}
