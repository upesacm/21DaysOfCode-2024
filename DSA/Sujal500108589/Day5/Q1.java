
import java.util.Scanner;

public class Q1 {
    public static class Node{
        int val;
        Node next;
        Node(int val){
          this.val=val;
        }
    }
    public static class linkedList{
        Node head=null;
        void insert(int val){
            Node temp=new Node(val);
            if(head==null){
                head=temp;
            }else{
            Node t=head;
            while(t.next!=null){
                t=t.next;
            }
            t.next=temp;}
        }
        void display(){
            Node temp=head;
            while(temp!=null){
               System.out.print(temp.val+" ");
               temp=temp.next;
            }
            System.out.println();
        }
        void reversePrint(Node temp){
            if(temp==null)return;
            reversePrint(temp.next);
            System.out.print(temp.val+" ");
        }
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        linkedList ll=new linkedList();
        System.out.println("Enter number of nodes");
        int n=in.nextInt();
        System.out.println("enter nodes values");
        for(int i=0;i<n;i++){
            int x=in.nextInt();
            ll.insert(x);
        }
        ll.display();
        Node t=ll.head;
        System.out.println("Reversed printed list");
        ll.reversePrint(t);
    }
}
