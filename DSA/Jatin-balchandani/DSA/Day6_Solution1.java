/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Day6_Solution1 {
    public String hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return "no cycle";
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return "cycle";
            }
        }

        return "no cycle";
    }

    public static void main(String[] args) {
        Day6_Solution1 solution = new Day6_Solution1();

        // Example linked list: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = head.next;  // Creating a cycle

        System.out.println(solution.hasCycle(head));  // Expected output: cycle

        // Example linked list: 1 -> 2 -> 3 -> 4 (no cycle)
        ListNode head2 = new ListNode(1);
        head2.next = new ListNode(2);
        head2.next.next = new ListNode(3);
        head2.next.next.next = new ListNode(4);

        System.out.println(solution.hasCycle(head2));  // Expected output: no cycle
    }
}
