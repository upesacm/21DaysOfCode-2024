// Floyd's Cycle-Finding Algorithm, also known as the "tortoise and hare" algorithm.
class Node {
    int data;
    Node next;

    Node () {
        this.next = null;
    }

    Node (int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkList {
    Node head;

    LinkList() {
        this.head = null;
    }

    LinkList(int[] arr) {
        this.head = null;
        for (int i : arr) {
            this.insert(i);
        }
    }

    public void insert(int data) {
        Node new_node = new Node(data);
        
        if (head == null) {
            head = new_node;
        }
        else {
            Node temp = head;

            while(temp.next != null) {
                temp = temp.next;
            }
            
            temp.next = new_node;
        }
    }

    public void display() {
        Node temp = head;

        while(temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }

        System.out.println("null");
    }

    public boolean hasLoop() {
        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
}

public class Q1 {

    public static void main(String[] args) {
        LinkList list = new LinkList(new int[]{1, 2, 3});
        list.head.next.next.next = list.head; // making the cycle
        // list.display();

        if (list.hasLoop()) {
            System.out.println("cycle");
        }
        else {
            System.out.println("no cycle");
        }
    }
}