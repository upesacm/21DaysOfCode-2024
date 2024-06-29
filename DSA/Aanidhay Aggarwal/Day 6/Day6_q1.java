import java.util.Scanner;
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

        for (int i = 1; i < values.size() - 1; ++i) {
            current.next = new ListNode(values.get(i));
            current = current.next;
        }

        current.next = head;  // Form a cycle

        return head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of nodes in the linked list:");
        int numNodes = scanner.nextInt();

        Vector<Integer> values = new Vector<>();

        System.out.println("Enter the values for the nodes:");
        for (int i = 0; i < numNodes; ++i) {
            values.add(scanner.nextInt());
        }

        ListNode head = createLinkedList(values);

        String result = checkCycle(head);
        System.out.println("Result: " + result);
    }
}
