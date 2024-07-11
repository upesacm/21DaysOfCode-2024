

public class Day5_Solution2 {
    // Method to compare two singly linked lists
    public static String compareLists(ListNode head1, ListNode head2) {
        ListNode current1 = head1;
        ListNode current2 = head2;

        while (current1 != null && current2 != null) {
            if (current1.val != current2.val) {
                return "different";
            }
            current1 = current1.next;
            current2 = current2.next;
        }

        // If both lists reached the end simultaneously, they are identical
        if (current1 == null && current2 == null) {
            return "identical";
        }

        // If one list is longer than the other, they are different
        return "different";
    }

    public static void main(String[] args) {
        // Example linked list 1: 1 -> 2 -> 3
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);

        // Example linked list 2: 1 -> 2 -> 3
        ListNode head2 = new ListNode(1);
        head2.next = new ListNode(2);
        head2.next.next = new ListNode(3);

        System.out.println(compareLists(head1, head2));  // Expected output: identical

        // Example linked list 3: 1 -> 2 -> 4
        ListNode head3 = new ListNode(1);
        head3.next = new ListNode(2);
        head3.next.next = new ListNode(4);

        System.out.println(compareLists(head1, head3));  // Expected output: different
    }
}
