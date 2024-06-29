class Node {
    int data;
    Node next;
    public Node(int data) {this.data = data;}
}

class Day_5_Question_1 {
    public static void printReverseLinkedList(Node head) {
        if (head == null)
            return;
        
        printReverseLinkedList(head.next);
        System.out.printf("%d ", head.data);
    }
    
    public static void main(String[] args) {
        Node n1 = new Node(1);
        Node n2 = new Node(2);
        Node n3 = new Node(3);
        n1.next = n2;
        n2.next = n3;
        n3.next = null;
        printReverseLinkedList(n1);
    }
}