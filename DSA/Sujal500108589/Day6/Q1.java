import java.util.*;
public class Q1 {

    public static class Node{
        int val;
        Node next;
        Node(int val){
          this.val=val;
        }
    }
    public static boolean findCycle(Node head){
        Node slow=head;
        Node fast=head;
        while(fast!=null){
            slow=slow.next;
            if(fast.next==null){return false;}
            fast=fast.next.next;
            if(slow==fast)return true;
        }
        return false;
    }
    
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter number of nodes");
        int n=in.nextInt();
        System.out.println("enter nodes values");
        Node head=null;
        for(int i=0;i<n;i++){
            int x=in.nextInt();
            Node temp=new Node(x);
            if(head==null){
                head=temp;
            }else{
                Node t=head;
                while(t.next!=null){
                    t=t.next;
                }
                t.next=temp;}
        }
        Node temp=head;
        while(temp.next!=null){
            temp=temp.next;
        }
        //this line helps last node join to second node change accordingly 
        temp.next=head.next;
        if(findCycle(head)){
            System.out.println("Cycle");
        }else{
            System.out.println("No cycle");
        }
        in.close();
    }
}
