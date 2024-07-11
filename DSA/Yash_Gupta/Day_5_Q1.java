// Yash Gupta 500125397
public class Day_5_Q1 {
    public static Node reverseLinkedList(Node head)
    {
        if(head==null){return null;}

        Node prev = null;
        Node current = head;
        Node nextNode= null;

        while (current != null) {
            nextNode = current.next;
            current.next = prev;    
            prev = current;         
            current = nextNode;      
        }
        return prev;
    }
    public static void printLinkedList(Node head)
    {
        while(head!=null)
        {
            System.out.println(head.val);
            head=head.next;
        }
    }
    public static void main(String[] args) {
        Node head=new Node(1);
        head.next=new Node(2);
        head.next.next=new Node(3);
        head=reverseLinkedList(head);
        printLinkedList(head);
    }
}

class Node{
    int val;
    Node next;
    Node(int val){
        this.val=val;
        next=null;
    }
}
//Time Complexity O(N)
//Auxillary space O(1)