import java.util.Stack;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class ReversePrintLinkedList {
    public static void printReverse(ListNode head) {
        Stack<Integer> stack = new Stack<>();
        
        ListNode current = head;
        while (current != null) {
            stack.push(current.val);
            current = current.next;
        }
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        printReverse(head);  
    }
}
