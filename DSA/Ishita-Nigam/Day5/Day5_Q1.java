import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class Day5_Q1 {

    public static void printReverse(ListNode head) {
        if (head == null) {
            return;
        }
        printReverse(head.next);
        System.out.print(head.val + " ");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of elements in the linked list:");
        int n = scanner.nextInt();

        if (n == 0) {
            System.out.println("The list is empty.");
            return;
        }

        System.out.println("Enter the elements of the linked list:");
        ListNode head = new ListNode(scanner.nextInt());
        ListNode current = head;

        for (int i = 1; i < n; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
        }

        System.out.println("The elements of the list in reverse order are:");
        printReverse(head);
    }
}
