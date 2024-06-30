import java.util.Stack;

// Definition for singly-linked list node
class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class Day5_Solution1 {
    // Method to print elements of the linked list in reverse order
    public static void printReverse(ListNode head) {
        Stack<Integer> stack = new Stack<>();

        // Step 1: Traverse the linked list and push elements onto the stack
        ListNode current = head;
        while (current != null) {
            stack.push(current.val);
            current = current.next;
        }

        // Step 2: Pop elements from the stack and print them
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }

    public static void main(String[] args) {
        // Example linked list: 1 -> 2 -> 3
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);

        System.out.print("Output: ");
        printReverse(head);  // Expected output: 3 2 1
    }
}
