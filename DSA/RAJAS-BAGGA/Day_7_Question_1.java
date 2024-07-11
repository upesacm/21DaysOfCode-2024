public class Day_7_Question_1 {
    public static SinglyLinkedListNode removeDuplicates(SinglyLinkedListNode llist) {
        // Write your code here
            SinglyLinkedListNode save = llist;
            
            while (llist.next != null) {
                if (llist.data == llist.next.data) {
                    llist.next = llist.next.next;
                    continue;
                }
                llist = llist.next;
            }
            return save;
        }
}
