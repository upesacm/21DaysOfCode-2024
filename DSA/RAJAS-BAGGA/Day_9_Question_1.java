class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
    };

    public Node() {
    };
}

class Stack {
    public Node head = null;

    public void push(int data) {
        Node node = new Node(data);
        if (head == null) {
            head = node;
            head.next = null;
            return;
        }
        node.next = head;
        head = node;
    }

    public int pop() {
        if (head == null)
            return -1;
        Node temp = head;
        this.head = head.next;
        int data = temp.data;
        temp = null;
        return data;
    }

    public int getMax() {

        Node tempHead = head;
        int sum = 0;
        while (tempHead != null) {
            sum += tempHead.data;
            tempHead = tempHead.next;
        }
        return sum;
    }

    public void display() {
        if (head == null) {
            System.out.println("Stack empty");
            return;
        }
        Node tempHead = head;
        while (tempHead != null) {
            System.out.println(tempHead.data);
            tempHead = tempHead.next;
        }
    }

}

public class Day_9_Question_1 {
    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(0);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        System.out.println(stack.getMax());
    }
}
