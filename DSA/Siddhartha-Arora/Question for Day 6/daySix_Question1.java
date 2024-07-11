/*# Questions for Day 6 - (26/06/2024)
## DSA:
*Question 1:* Write a function to check if a singly linked list contains a cycle. Return "cycle" if a loop exists, otherwise return "no cycle".
##### Inputs:
- A singly linked list.
##### Output:
- "cycle" if there is a cycle, otherwise "no cycle".
##### Example:
Linked list: 1 -> 2 -> 3 -> 4 -> 2 (cycle)

Output: cycle

*/
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}
public class daySix_Question1 {
    public static String checkCycle(ListNode head){
        boolean flag =false;
        ListNode slowPointer=head;
        ListNode fastPointer=head;
        while(fastPointer!=null&&fastPointer.next!=null){
            slowPointer=slowPointer.next;
            fastPointer=fastPointer.next.next;
            if(slowPointer==fastPointer){
                flag=true;
                break;
            }
        }
        return flag?"cycle":"no cycle";
    }

    
    
}
