class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Solution {
    public int getMergeNode(ListNode head1, ListNode head2) {
        int len1 = getLength(head1);
        int len2 = getLength(head2);
        ListNode longer = len1 > len2 ? head1 : head2;
        ListNode shorter = len1 > len2 ? head2 : head1;

        int diff = Math.abs(len1 - len2);
        while (diff-- > 0) {
            longer = longer.next;
        }

        while (longer != null && shorter != null) {
            if (longer == shorter) {
                return longer.val;
            }
            longer = longer.next;
            shorter = shorter.next;
        }
        return -1;
    }

    private int getLength(ListNode head) {
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }

    public static void main(String[] args) {
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        node1.next = node2;
        node2.next = node3;
        node4.next = node5;
        node5.next = node3;
        Solution solution = new Solution();
        System.out.println(solution.getMergeNode(node1, node4));
    }
}
