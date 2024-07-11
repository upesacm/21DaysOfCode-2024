class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedListComparison {
    
    public static String compareLists(Node head1, Node head2) {
        Node current1 = head1;
        Node current2 = head2;
        
        while (current1 != null && current2 != null) {
            if (current1.data != current2.data) {
                return "different";
            }
            current1 = current1.next;
            current2 = current2.next;
        }
    
        if (current1 == null && current2 == null) {
            return "identical";
        } else {
            return "different";
        }
    }

    public static void main(String[] args) {
        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(3);
        Node head2 = new Node(1);
        head2.next = new Node(2);
        head2.next.next = new Node(3);
        System.out.println(compareLists(head1, head2)); 
    }
}
