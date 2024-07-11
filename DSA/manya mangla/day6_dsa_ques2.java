class ListNode {
    int value;
    ListNode next;

    ListNode(int value) {
        this.value = value;
        this.next = null;
    }
}

public class LinkedListMergePoint {

    public static int getLength(ListNode head) {
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }

    public static ListNode advanceListByN(ListNode head, int n) {
        while (n > 0 && head != null) {
            head = head.next;
            n--;
        }
        return head;
    }

    public static int findMergePoint(ListNode head1, ListNode head2) {
        int len1 = getLength(head1);
        int len2 = getLength(head2);

        if (len1 > len2) {
            head1 = advanceListByN(head1, len1 - len2);
        } else {
            head2 = advanceListByN(head2, len2 - len1);
        }

        while (head1 != null && head2 != null) {
            if (head1 == head2) {
                return head1.value;
            }
            head1 = head1.next;
            head2 = head2.next;
        }

        return -1; // Return -1 if there is no merge point
    }

    public static void main(String[] args) {
        // Creating two linked lists
        ListNode mergeNode = new ListNode(3);

        ListNode list1 = new ListNode(1);
        list1.next = new ListNode(2);
        list1.next.next = mergeNode;

        ListNode list2 = new ListNode(4);
        list2.next = new ListNode(5);
        list2.next.next = mergeNode;

        // Output the merge point value
        System.out.println(findMergePoint(list1, list2));  // Output: 3
    }
}
