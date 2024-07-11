import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    public void addAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } 
        else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    public void addAtBeginning(int data){
        Node newNode = new Node(data);
        if(head == null){
            head = newNode;
        } 
        else {
            newNode.next = head;
            head = newNode;
        }
    }

    public LinkedList reverseList(){
        LinkedList reverse = new LinkedList();
        Node temp = head;
        while(temp != null){
            reverse.addAtBeginning(temp.data);
            temp = temp.next;
        }
        return reverse;
    }

    public void printReverseList(){
        LinkedList reverse = reverseList();
        Node temp = reverse.head;
        while(temp != null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}

public class Day05_25June_Ques1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        LinkedList list1 = new LinkedList();

        System.out.print("Enter the number of elements in the list: ");
        int n1 = scanner.nextInt();

        System.out.print("Enter the elements: ");
        for (int i = 0; i < n1; i++) {
            list1.addAtEnd(scanner.nextInt());
        }
        scanner.close();
        
        list1.printReverseList();
    }
}
