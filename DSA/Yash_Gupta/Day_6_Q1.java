//Yash gupta 500125397
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Day_6_Q1 {
    public static String hasCycle(Node head) {
        //implementing Floyd's Cycle-Finding Algorithm
        if (head == null) {
            return "no cycle";
        }

        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;        
            fast = fast.next.next;   

            if (slow == fast) {
                return "cycle";         
            }
        }

        return "no cycle";                 
    }

    public static void main(String[] args) {
        //test case-1
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next= head.next;
        System.out.println(hasCycle(head));

        //test case-2
        head.next.next.next.next= new Node(5);
        System.out.println(hasCycle(head));
    }
}
//time complexity O(n)
//auxillary space O(1)