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

        // Return the merge point
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

    public static void main(String[] args) {
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);

        ListNode head2 = new ListNode(4);
        head2.next = new ListNode(5);
        head2.next.next = head1.next.next;  // Merge point

        int mergePoint = findMergePoint(head1, head2);
        System.out.println("Merge point: " + mergePoint);
    }
}
