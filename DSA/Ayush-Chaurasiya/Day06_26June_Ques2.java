
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
    public void addNode(Node node) {
        if (head == null) {
            head = node;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = node;
        }
    }

    public static Node findInsterectionPoint(LinkedList list1, LinkedList list2){
        Node headA = list1.head;
        Node headB = list2.head;

        while(headA != headB){
            headA = (headA == null ? list2.head : headA.next);
            headB = (headB == null ? list1.head : headB.next);
        }
        return headA;
    }
}

public class Day06_26June_Ques2 {

    public static void main(String[] args) {

        LinkedList list1 = new LinkedList();
        LinkedList list2 = new LinkedList();

        list1.addAtEnd(1);
        list1.addAtEnd(2);
        
        list2.addAtEnd(4);
        list2.addAtEnd(5);

        Node common = new Node(3);

        list1.addNode(common);
        list2.addNode(common);
        
        Node result = LinkedList.findInsterectionPoint(list1, list2);
        System.out.println(result.data);
    }
}
