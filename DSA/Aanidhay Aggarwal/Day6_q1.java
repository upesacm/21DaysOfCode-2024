import java.util.Vector;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class CheckCycle {

    public static String checkCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {  // A cycle exists
                return "cycle";
            }
        }

        return "no cycle";  // No cycle found
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
        Vector<Integer> values = new Vector<>();
        values.add(1);
        values.add(2);
        values.add(3);
        values.add(4);
        values.add(2);

        ListNode head = createLinkedList(values);

        String result = checkCycle(head);
        System.out.println(result);  // Output: cycle
    }
}
