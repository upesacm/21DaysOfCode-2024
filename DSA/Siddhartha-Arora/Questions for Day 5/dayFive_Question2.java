/*
**Question 2:** Create a function to compare two singly linked lists and determine if they are identical.

##### Inputs:
- Two singly linked lists.
##### Output:
- "identical" if the lists are the same, otherwise "different".

Example:

Linked list 1: 1 -> 2 -> 3

Linked list 2: 1 -> 2 -> 3

Output: identical
 */
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class dayFive_Question2 {
    // Function to compare two singly linked lists
    public static String compareLists(ListNode l1, ListNode l2) {
        ListNode current1 = l1;
        ListNode current2 = l2;

        while (current1 != null && current2 != null) {
            if (current1.val != current2.val) {
                return "different";
            }
            current1 = current1.next;
            current2 = current2.next;
        }

        if (current1 == null && current2 == null) {
            return "identical";
        } else {
            return "different";
        }
    }

    public static void main(String[] args) {
        // Example linked list 1: 1 -> 2 -> 3
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);

        // Example linked list 2: 1 -> 2 -> 3
        ListNode head2 = new ListNode(1);
        head2.next = new ListNode(2);
        head2.next.next = new ListNode(3);

       

        // Compare the linked lists
        System.out.println(compareLists(head1, head2)); // Output: different
    }
}
