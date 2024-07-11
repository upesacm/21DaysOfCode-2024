//Question-2
//Author - Ayush Dey

class ListNode {
    int val;
    ListNode next;
    
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    public int findMergePoint(ListNode headA, ListNode headB) {
        // Edge case: if either list is null, there's no merge point
        if (headA == null || headB == null)
            return -1; // or handle as per your requirement
        
        // Pointers for traversing both lists
        ListNode currA = headA;
        ListNode currB = headB;
        
        // Traverse until both pointers meet at the merge point or null
        while (currA != currB) {
            // Move pointers to next nodes
            currA = (currA == null) ? headB : currA.next;
            currB = (currB == null) ? headA : currB.next;
        }
        
        // If currA is not null, it means we found the merge point
        // Return the value of the merge point
        return (currA == null) ? -1 : currA.val; // or currB.val, since they are the same at merge point
    }
    
    public static void main(String[] args) {
  
        
        // Constructing the example linked lists
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        
        ListNode head2 = new ListNode(4);
        head2.next = new ListNode(5);
        head2.next.next = head1.next.next; // Pointing to the same node 3 in head1
        
        // Finding the merge point
        Solution solution = new Solution();
        int mergeValue = solution.findMergePoint(head1, head2);
        
        System.out.println("Merge point value: " + mergeValue); 
    }
}
