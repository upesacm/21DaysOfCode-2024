class Node {
    int data;
    Node next;
    Node(int data) {this.data = data;}
}

public class Day_6_Question_1 {
    public static String hasCycle(Node head) {
        Node slow = head;
        Node fast = head;
        
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow)
                return "cycle";
        }
        return "no cycle";
    }
    public static void main(String[] args) {
        Node n1 = new Node(1);
        n1.next = new Node(2);
        n1.next.next = new Node(3);
        n1.next.next.next = new Node(4);
        n1.next.next.next.next = n1.next;
        
        System.out.println(hasCycle(n1));
    }
}
