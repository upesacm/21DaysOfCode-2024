public static SinglyLinkedListNode removeDuplicates(SinglyLinkedListNode llist) {
            if (llist == null || llist.next == null) {
                return llist;
            }

            SinglyLinkedListNode current = llist;
            while (current.next != null) {
                if (current.data == current.next.data) {
                    current.next = current.next.next; // skip the duplicate node
                } else {
                    current = current.next; // move to the next distinct element
                }
            }

            return llist;
        }
    }

    static void printSinglyLinkedList(SinglyLinkedListNode node, String sep, BufferedWriter bufferedWriter) throws IOException {
        while (node != null) {
            bufferedWriter.write(String.valueOf(node.data));

            node = node.next;

            if (node != null) {
                bufferedWriter.write(sep);
            }
