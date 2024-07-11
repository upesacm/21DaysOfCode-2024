import java.util.*;

class Node {
    int data;
    Node next;
    Node(int data) {this.data = data;}
}

public class Day_6_Question_2 {
    public static int mergePoint(Node head1, Node head2) {
        HashSet<Node> seen = new HashSet<Node>();
        while (head1 != null && head2 != null) {
            if (head1 != null && !seen.add(head1))
                return head1.data;
                
            if (head2 != null && !seen.add(head2))
                return head2.data;
                
            head1 = head1.next;
            head2 = head2.next;
        }
        return -1;
    }
    public static void main(String[] args) {
        Node a1 = new Node(1);
        Node a2 = new Node(2);
        Node a3 = new Node(3);
        a1.next = a2;
        a2.next = a3;
        a3.next = null;
        
        Node b1 = new Node(4);
        Node b2 = new Node(5);
        b1.next = b2;
        b2.next = a3;
        System.out.println(mergePoint(a1, b1));
    }
}
