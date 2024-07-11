class Day_5_Question_2
{
    public static String isIdentical(Node head1,Node head2){
        while(!(head1==null && head2==null)){
            if(head1==null || head2==null){
                return "different";
            }
            else if(head1.data != head2.data){
                return "different";
            }
            head1=head1.next;
            head2=head2.next;
        }
        return "identical";
    }
    public static void main(String args[]){
        Node head1=new Node(1);
        head1.next=new Node(2);
        head1.next.next=new Node(3);
        
        Node head2=new Node(1);
        head2.next=new Node(2);
        head2.next.next=new Node(3);
        
        System.out.println(isIdentical(head1,head2));
    }
}