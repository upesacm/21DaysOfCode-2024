public class LinkedList {
    Node head;

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public boolean areIdentical(LinkedList list1, LinkedList list2) {
        Node node1 = list1.head;
        Node node2 = list2.head;

        while (node1!= null && node2!= null) {
            if (node1.data!= node2.data) {
                return false;
            }
            node1 = node1.next;
            node2 = node2.next;
        }

        if (node1!= null || node2!= null) {
            return false;
        }

        return true;
    }

    public static void main(String[] args) {
        LinkedList list1 = new LinkedList();
        list1.head = new Node(1);
        list1.head.next = new Node(2);
        list1.head.next.next = new Node(3);

        LinkedList list2 = new LinkedList();
        list2.head = new Node(1);
        list2.head.next = new Node(2);
        list2.head.next.next = new Node(3);

        LinkedList list3 = new LinkedList();
        list3.head = new Node(1);
        list3.head.next = new Node(2);
        list3.head.next.next = new Node(4);

        LinkedList comparator = new LinkedList();

        System.out.println(comparator.areIdentical(list1, list2)? "identical" : "different"); // Output: identical
        System.out.println(comparator.areIdentical(list1, list3)? "identical" : "different"); // Output: different
    }
}
