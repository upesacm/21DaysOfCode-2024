class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        this.next=null;
    }
}
public class Day5_1 {
    public static Node reverseLL(Node head){
        if(head == null || head.next == null){
            return head;
        }
        Node newHead = reverseLL(head.next);
        Node front = head.next;
        front.next = head;
        head.next = null;
        return newHead;
    }
    private static Node ConverArray(int [] arr){
        if(arr.length == 0){
            return null;
        }
        Node head = new Node(arr[0]);
        Node mover = head;

        for(int i = 1; i<arr.length; i++){
            Node temp = new Node(arr[i]);
            mover.next = temp;
            mover = temp;
        }
        return head;
    }
    private static void printList(Node head){
    Node temp = head;
    while(temp != null){
        System.out.print(temp.data+"-->");
        temp = temp.next;
    }
    System.out.println("Null");
}
    public static void main(String[] args) {
        int [] arr = { 2,4,6,8};
        Node head = ConverArray(arr);
        printList(head);
        head = reverseLL(head);
        printList(head);

        
    }
}
