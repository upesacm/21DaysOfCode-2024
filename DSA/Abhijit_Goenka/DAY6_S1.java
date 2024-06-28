/*
 Write a function to check if a singly linked list contains a cycle. Return "cycle" if a loop exists, otherwise return "no cycle".

Inputs:
A singly linked list.
Output:
"cycle" if there is a cycle, otherwise "no cycle".
Example:
Linked list: 1 -> 2 -> 3 -> 4 -> 2 (cycle)

Output: cycle
 */




class ListNode {
    int value;
    ListNode next;

    ListNode(int value) {
        this.value = value;
        this.next = null;
    }
}

public class DAY6_S1 {

    public static String hasCycle(ListNode head) {
        if (head == null) {
            return "no cycle";
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;          // move slow by one step
            fast = fast.next.next;     // move fast by two steps

            if (slow == fast) {
                return "cycle";       // cycle detected
            }
        }

        return "no cycle";             // no cycle
    }

    public static void main(String[] args) {
        // Example usage
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);

        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node2; // Creating a cycle here

        System.out.println(hasCycle(node1)); // Output: cycle

        node4.next = null; // Removing the cycle

        System.out.println(hasCycle(node1)); // Output: no cycle
    }
}
