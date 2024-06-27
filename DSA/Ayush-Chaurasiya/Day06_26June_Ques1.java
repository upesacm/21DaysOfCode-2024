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
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }
    public String checkLoop(){
        Node slow = head;
        Node fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            if(fast.next != null){
                slow = slow.next;
                fast = fast.next.next;
                if(slow == fast){
                    return "cycle";
                }
            }
        }
        return "no cycle";
    }
}

public class Day06_26June_Ques1 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        LinkedList list1 = new LinkedList();

        System.out.print("Enter the number of elements in the first linked list: ");
        int n1 = scanner.nextInt();
        System.out.print("Enter the elements of the first linked list: ");
        for (int i = 0; i < n1; i++) {
            list1.addAtEnd(scanner.nextInt());
        }

        scanner.close();

        String result = list1.checkLoop();
        System.out.println(result);
    }
}
