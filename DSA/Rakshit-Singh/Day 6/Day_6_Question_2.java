class Day_6_Question_2
{
    public static int merging_point(Node head1,Node head2){
        while(head1!=null || head2!=null){
            if(head1.data==head2.data){
                return head1.data;
            }
            head1=head1.next;
            head2=head2.next;
        }
        return -1;
    }
    public static void main(String args[]){
        Node head1=new Node(1);
        head1.next=new Node (2);
        head1.next.next=new Node(3);
        
        Node head2=new Node(4);
        head2.next=new Node(5);
        head2.next.next=new Node(3);
        
        System.out.println(merging_point(head1,head2));
    }
}