import java.util.Scanner;

public class LinkedList {
    Node head;

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public void addNode(int data) {
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

    public boolean areIdentical(LinkedList list1, LinkedList list2) {
        Node node1 = list1.head;
        Node node2 = list2.head;

        while (node1 != null && node2 != null) {
            if (node1.data != node2.data) {
                return false;
            }
            node1 = node1.next;
            node2 = node2.next;
        }

        if (node1 != null || node2 != null) {
            return false;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        LinkedList list1 = new LinkedList();
        System.out.print("Enter the number of elements for list 1: ");
        int n1 = scanner.nextInt();
        System.out.println("Enter the elements for list 1:");
        for (int i = 0; i < n1; i++) {
            list1.addNode(scanner.nextInt());
        }

        LinkedList list2 = new LinkedList();
        System.out.print("Enter the number of elements for list 2: ");
        int n2 = scanner.nextInt();
        System.out.println("Enter the elements for list 2:");
        for (int i = 0; i < n2; i++) {
            list2.addNode(scanner.nextInt());
        }

        LinkedList comparator = new LinkedList();

        System.out.println(comparator.areIdentical(list1, list2) ? "identical" : "different");
    }
}
