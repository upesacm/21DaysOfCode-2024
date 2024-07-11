class Day_5_Question_1
{
    public static String reverse(Node head){
        String s="";
        while(head!=null){
            s=head.data + " "+s;
            head=head.next;
        }
        return s;
    }
    public static void main(String args[]){
        Node head = new Node(1);
        head.next=new Node(2);
        head.next.next= new Node(3);
        System.out.println(reverse(head));
    }
}