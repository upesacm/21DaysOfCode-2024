//Yash gupta 500125397
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Day_6_Q2 {
    public static int getIntersectionNode(Node head1, Node head2)
    {
        while (head2 != null) {//traversing the list2
            Node temp = head1;
            while (temp != null) {//traversing list1 for each element of list2
                if (temp == head2) {//comparing address
                    return head2.data;
                }
                temp = temp.next;
            }
            head2 = head2.next;
        }
        return -1;
    }
    public static void main(String[] args)
    {
        //test case-1
        Node head1=new Node(1);
        head1.next=new Node(2);
        head1.next.next=new Node(3);

        Node head2=new Node(4);
        head2.next=new Node(5);
        head2.next.next=head1.next.next;

        System.out.println(getIntersectionNode(head1, head2));
    }
}
//time complexity O(m*n)
//auxillary space O(1)