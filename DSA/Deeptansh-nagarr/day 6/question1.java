// : Write a function to check if a singly linked list contains a cycle. Return "cycle" if a
// loop exists, otherwise return "no cycle".
// Inputs:
// • A singly linked list.
// Output:
// • "cycle" if there is a cycle, otherwise "no cycle".
// Example:
// # Linked list: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
// # Output: cycle

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Solution {
    public String hasCycle(ListNode head) {
        if (head == null) return "no cycle";
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
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node2;

        Solution solution = new Solution();
        System.out.println(solution.hasCycle(node1));
    }
}
