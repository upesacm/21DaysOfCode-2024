class ListNode {
    int value;
    ListNode next;

    ListNode(int value) {
        this.value = value;
        this.next = null;
    }
}

public class MergePointLinkedList {
    
    // Function to calculate the length of a linked list
    public static int getLength(ListNode head) {
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }
    
    // Function to find the merge point
    public static int findMergePoint(ListNode headA, ListNode headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        // Align the start of both lists
        while (lenA > lenB) {
            headA = headA.next;
            lenA--;
        }
        while (lenB > lenA) {
            headB = headB.next;
            lenB--;
        }

        // Traverse both lists together to find the merge point
        while (headA != null && headB != null) {
            if (headA == headB) {
                return headA.value;
            }
            headA = headA.next;
            headB = headB.next;
        }

        return -1; // No merge point found
    }

    public static void main(String[] args) {
        // Creating two linked lists that merge at node with value 3
        // List 1: 1 -> 2 -> 3
        // List 2: 4 -> 5 -> 3

        ListNode merge = new ListNode(3);

        ListNode headA = new ListNode(1);
        headA.next = new ListNode(2);
        headA.next.next = merge;

        ListNode headB = new ListNode(4);
        headB.next = new ListNode(5);
        headB.next.next = merge;

        int mergePoint = findMergePoint(headA, headB);
        if (mergePoint != -1) {
            System.out.println("Merge Point: " + mergePoint);  // Output: 3
        } else {
            System.out.println("No merge point.");
        }
    }
}
