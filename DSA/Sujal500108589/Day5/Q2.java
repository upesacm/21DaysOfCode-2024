import java.util.Scanner;

public class Q2 {
    public static class Node{
        int val;
        Node next;
        Node(int val){
          this.val=val;
        }
    }
    public static class linkedList{
        Node insert(Node head, int val) {
            Node temp = new Node(val);
            if (head == null) {
                head = temp;
            } else {
                Node x = head;
                while (x.next != null) {
                    x = x.next;
                }
                x.next = temp;
            }
            return head;
        }

        public static boolean isIdentical(Node h1,Node h2){
            Node t1=h1;
            Node t2=h2;
            while(t1!=null && t2!=null){
                if(t1.val!=t2.val){
                    return false;
                }
                t1=t1.next;
                t2=t2.next;
            }
            return t1 == null && t2 == null;
        }
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        linkedList ll=new linkedList();
        Node head1=null;
        Node head2=null;
        System.out.println("Enter first linked list nodes values:");
        for(int i=0;i<5;i++){
            int x=in.nextInt();
            head1=ll.insert(head1,x);
        }
        System.out.println("Enter second linked list nodes values:");
        for(int i=0;i<5;i++){
            int x=in.nextInt();
            head2=ll.insert(head2,x);
        }
        if(linkedList.isIdentical(head1,head2)){
            System.out.println("Identical LinkedLists");
        }else{
            System.out.println("Not Identical");
        }
    }
}
