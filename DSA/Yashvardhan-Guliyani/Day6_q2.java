class ListNode {
    int val;
    ListNode next;
    
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class LinkedListMergePoint {
    public static int findMergePoint(ListNode head1, ListNode head2) {
        if (head1 == null || head2 == null) {
            return -1; 
        }
        
        ListNode pointer1 = head1;
        ListNode pointer2 = head2;
        
        while (pointer1 != pointer2) {
            pointer1 = pointer1.next;
            pointer2 = pointer2.next;
            if (pointer1 == null) {
                pointer1 = head2;
            }
            if (pointer2 == null) {
                pointer2 = head1;
            }
        }
        return (pointer1 != null) ? pointer1.val : -1;
    }
    
    public static void main(String[] args) {
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        ListNode head2 = new ListNode(4);
        head2.next = new ListNode(5);
        ListNode mergeNode = new ListNode(3);
        head1.next.next = mergeNode;
        head2.next.next = mergeNode;
        int mergeValue = findMergePoint(head1, head2);
        System.out.println("Merge point value: " + mergeValue);
    }
}
