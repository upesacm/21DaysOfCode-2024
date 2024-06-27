/*
  Find Merge Point in Linked Lists Determine the node where two singly linked lists merge. Return the value of this node.

Inputs:
Two singly linked lists.
Output:
The value of the merging node.
Example:
Linked list 1: 1 -> 2 -> 3

Linked list 2: 4 -> 5 -> 3

Output: 3
 */
class ListNode {
    int value;
    ListNode next;

    ListNode(int value) {
        this.value = value;
        this.next = null;
    }
}

public class DAY6_S2 {

    public static int findMergePoint(ListNode head1, ListNode head2) {
        int length1 = getLength(head1);
        int length2 = getLength(head2);

        
        if (length1 > length2) {
            head1 = moveForward(head1, length1 - length2);
        } else {
            head2 = moveForward(head2, length2 - length1);
        }

    
        while (head1 != null && head2 != null) {
            if (head1 == head2) {
                return head1.value;
            }
            head1 = head1.next;
            head2 = head2.next;
        }

        return -1; // No merge point found
    }

    private static int getLength(ListNode head) {
        int length = 0;
        while (head != null) {
            length += 1;
            head = head.next;
        }
        return length;
    }

    private static ListNode moveForward(ListNode head, int steps) {
        while (steps > 0 && head != null) {
            head = head.next;
            steps -= 1;
        }
        return head;
    }

    public static void main(String[] args) {
        // Creating linked list 1: 1 -> 2 -> 3
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);

        // Creating linked list 2: 4 -> 5 -> 3
        ListNode head2 = new ListNode(4);
        head2.next = new ListNode(5);
        head2.next.next = head1.next.next; // Merging point is the node with value 3

        System.out.println(findMergePoint(head1, head2)); // Output: 3
    }
}

