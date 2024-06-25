class Node {
    int data;
    Node next;
    public Node(int data) {this.data = data;}
}

public class Day_5_Question_2 {
    public static String isIdentical(Node head1, Node head2) {
        
        while (head1 != null || head2 != null) {
            if (head1 == null && head2 == null)
                break;
            else if (head1 == null && head2 != null)
                return "different";
            
            else if (head1 != null && head2 == null)
                return "different";
            
            else if (head1.data != head2.data)
                return "different";
            
            head1 = head1.next;
            head2 = head2.next;
        }
        
        return "identical";
    }
    
    public static void main(String[] args) {
        Node a1 = new Node(1);
        Node a2 = new Node(2);
        Node a3 = new Node(3);
        a1.next = a2;
        a2.next = a3;
        a3.next = null;
        
        Node b1 = new Node(1);
        Node b2 = new Node(2);
        Node b3 = new Node(3);
        b1.next = b2;
        b2.next = b3;
        b3.next = null;
        
        System.out.println(isIdentical(a1, b1));
    }
    
}
