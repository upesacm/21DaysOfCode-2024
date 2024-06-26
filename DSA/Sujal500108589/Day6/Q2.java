import java.util.*;
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
        public static int findIntersectionNode(Node h1,Node h2){
            Node temp1=h1;
            Node temp2=h2;
            int len1=0;
            int len2=0;
            while(temp1!=null){
                len1++;
                temp1=temp1.next;
            }
            while(temp2!=null){
                len2++;
                temp2=temp2.next;
            }
            temp1=h1;
            temp2=h2;
            if(len1>len2){
                int size=len1-len2;
                for(int i=1;i<=size;i++){
                    temp1=temp1.next;
                }
            }else{
                int size=len2-len1;
                for(int i=1;i<=size;i++){
                    temp2=temp2.next;
                }
            }
            while(temp1!=temp2){
                temp1=temp1.next;temp2=temp2.next;
            }
            return temp1.val;
        }
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        linkedList ll=new linkedList();
        Node head1=null;
        Node head2=null;
        System.out.println("Enter number of nodes for first linkedlist");
        int n1=in.nextInt();
        System.out.println("Enter first linked list nodes values:");
        for(int i=0;i<n1;i++){
            int x=in.nextInt();
            head1=ll.insert(head1,x);
        }
        System.out.println("Enter number of nodes for second linkedlist");
        int n2=in.nextInt();
        System.out.println("Enter second linked list nodes values:");
        for(int i=0;i<n2;i++){
            int x=in.nextInt();
            head2=ll.insert(head2,x);
        }
        Node temp=head2;
        Node t=head1;
        temp.next.next.next=t.next.next;
        int ans=linkedList.findIntersectionNode(head1,head2);
        System.out.println("Node value is"+ans);
    }
}
