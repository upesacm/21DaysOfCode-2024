import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class Day6_Q1 {
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
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of nodes in the linked list:");
        int n = scanner.nextInt();

        if (n <= 0) {
            System.out.println("no cycle");
            return;
        }

        System.out.println("Enter the values of the nodes:");
        ListNode head = new ListNode(scanner.nextInt());
        ListNode current = head;
        ListNode cycleNode = null;

        for (int i = 1; i < n; i++) {
            int value = scanner.nextInt();
            current.next = new ListNode(value);
            current = current.next;

            if (i == 1) {
                cycleNode = current;
            }
        }

        if (cycleNode != null) {
            current.next = cycleNode;
        }

        System.out.println(hasCycle(head));
    }
}
