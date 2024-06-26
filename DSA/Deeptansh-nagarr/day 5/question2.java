class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    boolean isEqual(LinkedList other) {
        Node current1 = this.head;
        Node current2 = other.head;

        while (current1 != null && current2 != null) {
            if (current1.data != current2.data) {
                return false;
            }
            current1 = current1.next;
            current2 = current2.next;
        }

        return current1 == null && current2 == null;
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList list1 = new LinkedList();
        list1.head = new Node(1);
        list1.head.next = new Node(2);
        list1.head.next.next = new Node(3);

        LinkedList list2 = new LinkedList();
        list2.head = new Node(1);
        list2.head.next = new Node(2);
        list2.head.next.next = new Node(3);

        if (list1.isEqual(list2)) {
            System.out.println("identical");
        } else {
            System.out.println("different");
        }
    }
}
