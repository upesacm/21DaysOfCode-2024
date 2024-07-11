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
        // Creating a linked list with a cycle:
        // 1 -> 2 -> 3 -> 4 -> 2 (cycle)
        ListNode head = new ListNode(1);
        ListNode second = new ListNode(2);
        ListNode third = new ListNode(3);
        ListNode fourth = new ListNode(4);

        head.next = second;
        second.next = third;
        third.next = fourth;
        fourth.next = second;  // Creating a cycle here

        System.out.println(hasCycle(head));  // Output: cycle
    }
}
