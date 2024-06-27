class Day_6_Question_1
{
    public static String isCycle(Node head){
        String track=",";
        while(head!=null){
            String s=","+head.data+",";
            if(track.indexOf(s)!=-1){
                return "cycle";
            }
            track+=head.data+",";
            head=head.next;
        }
        return "no cycle";
    }
    public static void main(String args[]){
        Node head=new Node(1);
        head.next=new Node(2);
        head.next.next=new Node(3);
        head.next.next.next=new Node(4);
        head.next.next.next.next=new Node(2);
        System.out.println(isCycle(head));
    }
}