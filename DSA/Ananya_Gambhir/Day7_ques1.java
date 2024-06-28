import java.util.*;
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return head;
        }

        ListNode current = head;
        while (current != null && current.next != null) {
            if (current.val == current.next.val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }

        return head;
    }

    public static ListNode createLinkedList(int[] values) {
        if (values.length == 0) {
            return null;
        }
        ListNode head = new ListNode(values[0]);
        ListNode current = head;
        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
        }
        return head;
    }

  
    public static void printLinkedList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + " -> ");
            current = current.next;
        }
        System.out.println("None");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of elements in the sorted linked list:");
        int n = scanner.nextInt();
        int[] values = new int[n];

        System.out.println("Enter the elements of the sorted linked list:");
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
        }

        ListNode head = createLinkedList(values);

        System.out.println("Original list:");
        printLinkedList(head);

        Solution solution = new Solution();
        ListNode newHead = solution.deleteDuplicates(head);

        System.out.println("List after removing duplicates:");
        printLinkedList(newHead);

        scanner.close();
    }
}
