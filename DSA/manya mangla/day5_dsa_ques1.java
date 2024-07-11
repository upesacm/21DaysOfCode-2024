import java.util.Stack;

class ListNode {
    int value;
    ListNode next;

    ListNode(int value) {
        this.value = value;
        this.next = null;
    }
}

public class LinkedListReverse {
    public static void printReverseWithStack(ListNode head) {
        Stack<Integer> stack = new Stack<>();
        ListNode current = head;

        // Push all elements onto the stack
        while (current != null) {
            stack.push(current.value);
            current = current.next;
        }

        // Pop elements from the stack and print
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }

    public static void main(String[] args) {
        // Creating linked list: 1 -> 2 -> 3
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);

        printReverseWithStack(head);
        // Output: 3 2 1
    }
}
