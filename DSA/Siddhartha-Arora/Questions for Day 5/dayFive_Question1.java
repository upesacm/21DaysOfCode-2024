
/*# Questions for Day 5 - (25/06/2024)
## DSA:
**Question 1:** Given a singly linked list, write a function to print the elements in reverse order.
##### Inputs:
- A singly linked list.
##### Output:
- The elements of the list in reverse order.

Example:

Linked list: 1 -> 2 -> 3

Output: 3 2 1
 */
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class dayFive_Question1 {
    // Recursive function to print the list in reverse order
    public static void printReverse(ListNode head) {
        if (head == null) {
            return;
        }
        printReverse(head.next); // Recursive call with the next node
        System.out.print(head.val + " "); // Print the current node's value
    }

    public static void main(String[] args) {
        // Example linked list: 1 -> 2 -> 3
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);

        // Print the linked list in reverse order
        printReverse(head);
    }
}
