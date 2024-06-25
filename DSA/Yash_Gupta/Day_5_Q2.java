//Yash gupta 500125397
public class Day_5_Q2 {

    public static boolean areIdentical(Node head1, Node head2) {
        //creating a copy of both heads
        Node current1 = head1;
        Node current2 = head2;
        //traversing both the list and comparing each node
        while (current1 != null && current2 != null) {
            if (current1.value != current2.value) {
                return false;
            }
            current1 = current1.next;
            current2 = current2.next;
        }
        return (current1 == null && current2 == null);//checking if both the pointers have reached the end
    }

    public static void main(String[] args) {
        // test case-1
        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(3);
        head1.next.next.next = new Node(4);

        Node head2 = new Node(1);
        head2.next = new Node(2);
        head2.next.next = new Node(3);
        head2.next.next.next = new Node(4);

        if (areIdentical(head1, head2)) {
            System.out.println("identical");
        } else {
            System.out.println("different");
        }

    }
}
class Node {
    int value;
    Node next;

    Node(int value) {
        this.value = value;
        this.next = null;
    }
}


//time complexity O(n)
//auxillary space O(1)
