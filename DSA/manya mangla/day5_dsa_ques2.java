class ListNode {
    int value;
    ListNode next;

    ListNode(int value) {
        this.value = value;
        this.next = null;
    }
}

public class LinkedListComparison {
    public static String compareLists(ListNode head1, ListNode head2) {
        ListNode current1 = head1;
        ListNode current2 = head2;

        while (current1 != null && current2 != null) {
            if (current1.value != current2.value) {
                return "different";
            }
            current1 = current1.next;
            current2 = current2.next;
        }

        // Check if both lists have reached the end
        if (current1 == null && current2 == null) {
            return "identical";
        } else {
            return "different";
        }
    }

    public static void main(String[] args) {
        // Creating first linked list: 1 -> 2 -> 3
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);

        // Creating second linked list: 1 -> 2 -> 3
        ListNode head2 = new ListNode(1);
        head2.next = new ListNode(2);
        head2.next.next = new ListNode(3);

        // Comparing both lists
        String result = compareLists(head1, head2);
        System.out.println(result); // Output: identical

        // Creating third linked list: 1 -> 2 -> 4
        ListNode head3 = new ListNode(1);
        head3.next = new ListNode(2);
        head3.next.next = new ListNode(4);

        // Comparing first and third lists
        result = compareLists(head1, head3);
        System.out.println(result); // Output: different
    }
}
