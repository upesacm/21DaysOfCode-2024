import java.util.Scanner;
import java.util.Vector;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class MergePoint {
    public static int findMergePoint(ListNode head1, ListNode head2) {
        int len1 = length(head1);
        int len2 = length(head2);

        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) {
                head1 = head1.next;
            }
        } else {
            for (int i = 0; i < len2 - len1; i++) {
                head2 = head2.next;
            }
        }

        while (head1 != head2) {
            head1 = head1.next;
            head2 = head2.next;
        }

        return head1.val;
    }

    public static int length(ListNode head) {
        int len = 0;
        while (head != null) {
            len++;
            head = head.next;
        }
        return len;
    }

    public static ListNode createLinkedList(Vector<Integer> values) {
        ListNode head = new ListNode(values.get(0));
        ListNode current = head;

        for (int i = 1; i < values.size(); ++i) {
            current.next = new ListNode(values.get(i));
            current = current.next;
        }

        return head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of nodes in linked list 1:");
        int numNodes1 = scanner.nextInt();

        Vector<Integer> values1 = new Vector<>();

        System.out.println("Enter the values for linked list 1:");
        for (int i = 0; i < numNodes1; ++i) {
            values1.add(scanner.nextInt());
        }

        ListNode head1 = createLinkedList(values1);

        System.out.println("Enter the number of nodes in linked list 2:");
        int numNodes2 = scanner.nextInt();

        Vector<Integer> values2 = new Vector<>();

        System.out.println("Enter the values for linked list 2:");
        for (int i = 0; i < numNodes2; ++i) {
            values2.add(scanner.nextInt());
        }

        ListNode head2 = createLinkedList(values2);

        int mergeIndex = values1.size() - 1;
        ListNode current1 = head1;
        for (int i = 0; i < mergeIndex; ++i) {
            current1 = current1.next;
        }

        ListNode current2 = head2;
        while (current2.next != null) {
            current2 = current2.next;
        }

        current2.next = current1;

        int mergePoint = findMergePoint(head1, head2);
        System.out.println("Merge point: " + mergePoint);
    }
}
