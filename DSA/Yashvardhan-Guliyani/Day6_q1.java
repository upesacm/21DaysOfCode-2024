class ListNode {
    int val;
    ListNode next;
    
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class LinkedListCycleDetection {
    public static String hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return "no cycle";
        }
        
        ListNode slow = head;
        ListNode fast = head.next;
        
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return "no cycle";
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        
        return "cycle";
    }
    
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        ListNode second = new ListNode(2);
        ListNode third = new ListNode(3);
        ListNode fourth = new ListNode(4);
        
        head.next = second;
        second.next = third;
        third.next = fourth;
        fourth.next = second; 
        
        String result = hasCycle(head);
        System.out.println("Result: " + result);
    }
}
