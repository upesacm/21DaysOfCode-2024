// class Result {

    /*
     * Complete the 'removeDuplicates' function below.
     *
     * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
     * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
     */

    /*
     * For your reference:
     *
     * SinglyLinkedListNode {
     *     int data;
     *     SinglyLinkedListNode next;
     * }
     *
     */

    public static SinglyLinkedListNode removeDuplicates(SinglyLinkedListNode llist) {
    // If the list is empty or has only one node, no duplicates to remove
    if (llist == null || llist.next == null) {
        return llist;
    }
    
    SinglyLinkedListNode current = llist;
    
    while (current != null && current.next != null) {
        if (current.data == current.next.data) {
            // Duplicate found, remove the next node
            current.next = current.next.next;
        } else {
            // Move to the next node
            current = current.next;
        }
    }
    
    return llist;
}

// }
