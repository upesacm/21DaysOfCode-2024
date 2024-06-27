/**
 * Question 1:
 * Given a singly linked list, write a function to print the elements in reverse order.
 * 
 * Inputs:
 * A singly linked list.
 * 
 * Output:
 * The elements of the list in reverse order.
 * 
 * Example:
 * Linked list: 1 -> 2 -> 3
 * 
 * Output: 3 2 1
 */
import java.util.*;
class Node{
    public int data;
    Node next;
    Node(int data){
        this.data=data;
        this.next=null;
    }
}
public class Day5_Q1 {
    Node head;
    public Day5_Q1(){
        this.head=null;
    }
    
    public void Insert_End(int data){
        Node newNode = new Node(data);
        if(head==null){
            head=newNode;
            return;
        }
        Node current = head;
        while (current.next!=null) {
            current=current.next;
        }
        current.next=newNode;
    }
    public void Insert_beg(int data){
        Node newnode = new Node(data);
        newnode.next=head;
        head = newnode;
    }

    public void Create(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the number of elements you wanted to Insert");
        int n = scan.nextInt();
        if(head==null){
        for(int i=0;i<n;i++){
        System.out.println("Enter the data");
        int data = scan.nextInt();
        Insert_End(data);
        }
        System.out.println("LinkList is created");
        Display();
    }
        else{
            System.out.println("Link List is Already created");
        }
    }
    public void Display(){
        Node current = head;
        int count =0;
        while(current!=null) {
            System.out.print(current.data+"->");
            current=current.next;
            count++;
        }
        System.out.println(current);
        System.out.println("Number of Nodes = "+count);
    }
    public void Insert_after(int data,int x){
        Node newnode = new Node(data);
        if(head==null){
            head=newnode;
            return;
        }
        Node current = head;
        while (current!=null && current.data!=x) {
            current=current.next;
        }
        if(current==null){
            System.out.println("Your element doesn't exit");
        }
        else{
        newnode.next=current.next;
        current.next=newnode;
        }
    }
    public void Insert_before(int data,int x){
        Node newnode = new Node(data);
        if(head==null){
            head=newnode;
            return;
        }
        else if(head.data==x){
            newnode.next=head;
            head=newnode;
            return;
        }
        Node current = head;
        while (current.next!=null && current.next.data!=x) {
            current=current.next;
        }
        if(current.next==null){
            System.out.println("Your element doesn't exit");
        }
        else{
        newnode.next=current.next;
        current.next=newnode;
        }
    }   
    public void Insert_pos(int data,int pos){
        Node newnode = new Node(data);
        int i=1;
        if(head==null){
            head=newnode;
            return;
        }
        else if(pos==0){
            Insert_beg(data);
            return;
        }
        Node current = head;
        while (current!=null && pos>i) {
            current=current.next;
            i++;
        }
        if(current==null){
            System.out.println("Position not found in the linked list.");
        }
        else{
        newnode.next=current.next;
        current.next=newnode;
        }
    }
    public int Delete_beg(){
        if(head==null){
            throw new NoSuchElementException("List is empty");
        }
        else if(head.next==null){
            int temp = head.data;
            head=null;
            return temp;
        }
        int temp = head.data;
        head=head.next;
        return temp;
    }
    public int Delete_end(){
        if(head==null){
            throw new NoSuchElementException("List is empty");
        }
        else if(head.next==null){
            int temp = head.data;
            head=null;
            return temp;
        }
        Node current = head;
        while (current.next.next!=null) {
            current=current.next;
        }
        int temp = current.next.data;
        current.next=null;
        return temp;
    }
    public void Delete_element(int x){
        if(head==null){
            System.out.println("List is empty");
            return;
        }
        else if(head.next== null && head.data==x){
            head = null;
            return;
        }
        else if(head.next!= null && head.data==x){
            head = head.next;
            return;
        }
        Node current = head;
        while (current.next!=null && current.next.data!=x) {
            current=current.next;
        }
        if(current.next==null){
            System.out.println("Element not found in the linked list.");
        }
        else{
            current.next=current.next.next;
        }
    }
    public void Delete_pos(int pos){
        int i=1;
        if(head==null){
            System.out.println("List is empty");
            return;
        }
        else if(pos==0){
            Delete_beg();
            return;
        }
        Node current = head;
        while (current.next!=null && pos>i) {
            current=current.next;
            i++;
        }
        if(current.next==null){
            System.out.println("Position not found in the linked list.");
        }
        else{
        current.next=current.next.next;
        }
    }
    public void Count(){
        Node current = head;
        int count =0;
        while(current!=null) {
            current=current.next;
            count++;
        }
        System.out.println("Number of Nodes = "+count);
    }
    public void Sort(){
        Node i =head;
        while (i.next!=null) {
            Node j=i.next;
            while (j!=null) {
                if(i.data>j.data){
                    int temp = i.data;
                    i.data=j.data;
                    j.data=temp;
                }
                j=j.next;
            }
            i=i.next;
        }
    }
    public void Insert_sort(int data){
        Node newNode = new Node(data);
        if(head== null){
            head=newNode;
            return;
        }
        else if(head.data>data){
            Insert_beg(data);
            return;
        }
        Node current = head;
        while (current.next!=null && current.next.data<data) {
            current=current.next;
        }
        newNode.next=current.next;
        current.next=newNode;
    }
    public void Print_reverse(){
        reverse_static(head);
        System.out.println("null");
    }
    public void reverse_static(Node head){
        Node current = head;
        if(current==null){
            return;
        }
        reverse_static(current.next);
        System.out.print(current.data+"->");
    }
    public void Reverse(){
        Node current = head.next;
        Node prev = head;
        Node next = null;
        while (current!=null) {
            next=current.next;
            current.next=prev;
            prev=current;
            current=next;
        }
        head.next=null;
        head=prev;
    }
    public void Reverse_Recusion(){
        head = reverse_rec(head);
    }
    public Node reverse_rec(Node head){
        Node current = head;
        if(current==null || current.next==null){
            return current;
        }
        Node newhead = reverse_rec(current.next);
        current.next.next=current;
        current.next=null;
        return newhead;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Day5_Q1 list = new Day5_Q1();
        while(true){
            System.out.println("\tMenu");
            System.out.println("1) Create a Link List");
            System.out.println("2) Insert at End");
            System.out.println("3) Insert at beginning");
            System.out.println("4) Insert after data");
            System.out.println("5) Insert before data");
            System.out.println("6) Insert at nth position");
            System.out.println("7) Delete at beginning");
            System.out.println("8) Delete at End");
            System.out.println("9) Delete an element");
            System.out.println("10) Delete a position");
            System.out.println("11) Count Number of elements in the Link List");
            System.out.println("12) Sort the Link List");
            System.out.println("13) Add Element in sorted manner");
            System.out.println("14) Display");
            System.out.println("15) Print LinkList in Reverse");
            System.out.println("16) Store LinkList in Reverse(iterative)");
            System.out.println("17) Store LinkList in Reverse(recursion)");
            System.out.println("18) Exit");
            System.out.println("Enter your desired option");
            int choice = scan.nextInt();
            switch (choice) {
                case 1:
                list.Create();
                    break;
                case 2:
                System.out.println("Enter the data");
                int data= scan.nextInt();
                list.Insert_End(data);
                list.Display();
                    break;
                case 3:
                System.out.println("Enter the data");
                data= scan.nextInt();
                list.Insert_beg(data);
                list.Display();
                    break;
                case 4:
                System.out.println("Enter the element after which you wanted to Insert");
                int x = scan.nextInt();
                System.out.println("Enter the data");
                data= scan.nextInt();
                list.Insert_after(data,x);
                list.Display();
                    break;
                case 5:
                System.out.println("Enter the element before which you wanted to Insert");
                x = scan.nextInt();
                System.out.println("Enter the data");
                data= scan.nextInt();
                list.Insert_before(data,x);
                list.Display();
                    break;
                case 6:
                System.out.println("Enter the position at which you wanted to Insert");
                int pos = scan.nextInt();
                System.out.println("Enter the data");
                data= scan.nextInt();
                list.Insert_pos(data,pos);
                list.Display();
                    break;
                case 7:
                    try {
                        int deletedValue = list.Delete_beg();
                        System.out.println("Deleted value: " + deletedValue);
                    } 
                    catch (NoSuchElementException e) {
                        System.out.println(e.getMessage()); 
                    }
                list.Display();
                    break;
                case 8:
                try {
                    int deletedValue = list.Delete_end();
                    System.out.println("Deleted value: " + deletedValue);
                } 
                catch (NoSuchElementException e) {
                    System.out.println(e.getMessage()); 
                }
                list.Display();
                    break;
                case 9:
                System.out.println("Enter the element you wanted to delete");
                x= scan.nextInt();
                list.Delete_element(x);
                list.Display();
                    break;
                case 10:
                System.out.println("Enter the position you wanted to delete");
                pos = scan.nextInt();
                list.Delete_pos(pos);
                list.Display();
                    break;
                case 11:
                list.Count();
                    break;
                case 12:
                list.Sort();
                list.Display();
                    break;
                case 13:
                System.out.println("Enter the data");
                data= scan.nextInt();
                list.Insert_sort(data);
                list.Display();
                    break;
                case 14:
                list.Display();
                    break;
                case 15:
                list.Print_reverse();
                    break;
                case 16:
                list.Reverse();
                list.Display();   
                    break;
                case 17:
                    list.Reverse_Recusion();
                    list.Display();   
                        break;
                case 18:
                    System.exit(0);
                    break;
                default:
                System.out.println("Choose the correct option");
                    break;
            }
        }
    }
}
