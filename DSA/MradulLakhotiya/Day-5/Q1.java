class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Stack {
    Node top;

    Stack() {
        this.top = null;
    }

    public void push(int data) {
        Node new_node = new Node(data);

        if (top == null) {
            top = new_node;
        }
        else {
            new_node.next = top;
            top = new_node;
        }
    }

    public int pop() {
        if (top == null) {
            throw new IllegalStateException("Stack Is Empty");
        }
        else {
            int popped_int = top.data;
            top = top.next;
            return popped_int;
        }
    }

    public boolean isEmpty() {
        return top == null;
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

    public void printReverseInOrder() {
        Node temp = head;
        Stack st = new Stack();

        while(temp != null) {
            st.push(temp.data);
            temp = temp.next;
        }

        while(!st.isEmpty()) {
            System.out.print(st.pop() + " ");
        }
        System.out.println();
    }
}

public class Q1 {
    public static void main(String[] args) {
        int[] input = {1, 2, 3};
        LinkList list = new LinkList(input);
        list.printReverseInOrder();
        list.display();
    }
} 