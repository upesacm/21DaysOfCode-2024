import java.util.Scanner;

class SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode next;

    SinglyLinkedListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Day7_Q1 {

    public static SinglyLinkedListNode removeDuplicates(SinglyLinkedListNode head) {
        if (head == null) {
            return head;
        }
        SinglyLinkedListNode current = head;
        while (current != null && current.next != null) {
            if (current.data == current.next.data) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        return head;
    }

    public static void printLinkedList(SinglyLinkedListNode head) {
        SinglyLinkedListNode current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static SinglyLinkedListNode insertNodeAtEnd(SinglyLinkedListNode head, int data) {
        SinglyLinkedListNode newNode = new SinglyLinkedListNode(data);
        if (head == null) {
            head = newNode;
        } else {
            SinglyLinkedListNode current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
        return head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            SinglyLinkedListNode head = null;
            for (int j = 0; j < n; j++) {
                int data = scanner.nextInt();
                head = insertNodeAtEnd(head, data);
            }
            head = removeDuplicates(head);
            printLinkedList(head);
        }
        scanner.close();
    }
}