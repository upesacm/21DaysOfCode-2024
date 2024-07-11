public class LinkedList {
    // Define the Node class as a static nested class
    static class Node<T> {
        T data;
        Node<T> next;

        Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    public static void print(Node<Integer> head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void printReverse(Node<Integer> head) {
        if (head == null) {
            return;
        }
        printReverse(head.next);
        System.out.print(head.data + " ");
    }

    public static void main(String[] args) {
        Node<Integer> node1 = new Node<>(30);
        Node<Integer> node2 = new Node<>(40);
        Node<Integer> node3 = new Node<>(60);
        Node<Integer> head = node1;
        node1.next = node2;
        node2.next = node3;
        
        //print original linked list
        print(head);
        printReverse(head);//print reversed list
    }
}
