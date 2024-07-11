class ListNode {
    int value;
    ListNode next;

    ListNode(int value) {
        this.value = value;
        this.next = null;
    }
}

public class LinkedListCycle {

    public static String hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return "no cycle";
        }

        ListNode slow = head;
        ListNode fast = head.next;

        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return "no cycle";
            }
            slow = slow.next;
            fast = fast.next.next;
        }

        return "cycle";
    }

    public static void main(String[] args) {
        // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
        ListNode node4 = new ListNode(4);
        ListNode node3 = new ListNode(3);
        ListNode node2 = new ListNode(2);
        ListNode node1 = new ListNode(1);

        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node2;  // Creating the cycle here

        System.out.println(hasCycle(node1));  // Output: cycle
    }
}
