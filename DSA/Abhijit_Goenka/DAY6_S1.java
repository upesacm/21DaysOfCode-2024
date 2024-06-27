class ListNode {
    int value;
    ListNode next;

    ListNode(int value) {
        this.value = value;
        this.next = null;
    }
}

class DAY6_S1 {

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
        // Creating a list with a cycle: 1 -> 2 -> 3 -> 4 -> 2
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = head.next; // Creating the cycle

        System.out.println(hasCycle(head)); // Output: cycle

        
        head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);

        System.out.println(hasCycle(head)); 
    }
}

