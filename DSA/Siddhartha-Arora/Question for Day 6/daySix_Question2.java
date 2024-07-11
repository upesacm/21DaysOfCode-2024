
/*
*Question 2:* Find Merge Point in Linked Lists Determine the node where two singly linked lists merge. Return the value of this node.
##### Inputs:
- Two singly linked lists.
##### Output:
- The value of the merging node.
##### Example:

Linked list 1: 1 -> 2 -> 3

Linked list 2: 4 -> 5 -> 3
Output: 3


*/
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}
public class daySix_Question2 {
    public static int checkMergingPoint(ListNode list1,ListNode list2){
    
            //if l1.val==l2.val return the val
            if(list1==null||list2==null)return -1;
            int len1=getLength(list1);
            int len2=getLength(list2);
            while(len1>len2 ){
                list1=list1.next;
                len1--;
            }
            while(len2>len1){
                list2=list2.next;
                len2--;
            }
            while(list1!=null&&list2!=null){
                if(list1.val==list2.val)return list1.val;
                list1=list1.next;
                list2=list2.next;

            }


        return -1;
    }
    public static int getLength(ListNode l1){
        int length=0;
        while(l1!=null){
        length++;
        l1=l1.next;
        }
        return length;
    }
   
    
}
