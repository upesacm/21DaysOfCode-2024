import java.util.*;

class ListNode {
    int value;
    ListNode next;

    ListNode(int value) {
        this.value = value;
        this.next = null;
    }
}

public class LinkedListCycleChecker {
    public static String hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return "no cycle";
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next; // move slow pointer by 1
            fast = fast.next.next; // move fast pointer by 2

            if (slow == fast) {
                return "cycle"; // cycle detected
            }
        }

        return "no cycle"; // no cycle detected
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the linked list in the format:");
        String input = scanner.nextLine();
        String[] parts = input.split("->");

        Map<Integer, ListNode> nodeMap = new HashMap<>();
        ListNode head = null;
        ListNode current = null;
        for (int i = 0; i < parts.length; i++) {
            int value = Integer.parseInt(parts[i].trim());

            if (i == 0) {
                head = new ListNode(value);
                current = head;
            } else {
                if (nodeMap.containsKey(value)) {
                    current.next = nodeMap.get(value);
                    break;
                } else {
                    current.next = new ListNode(value);
                    current = current.next;
                }
            }

            nodeMap.put(value, current);
        }

        System.out.println(hasCycle(head));

        scanner.close();
    }
}
