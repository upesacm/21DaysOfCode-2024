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

    public static String compareLists(LinkedList list1, LinkedList list2) {
        Node current1 = list1.head;
        Node current2 = list2.head;

        while (current1 != null && current2 != null) {
            if (current1.data != current2.data) {
                return "different";
            }
            current1 = current1.next;
            current2 = current2.next;
        }

        if (current1 != null || current2 != null) {
            return "different";
        }

        return "identical";
    }
}

public class Day05_25June_Ques2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        LinkedList list1 = new LinkedList();
        LinkedList list2 = new LinkedList();

        System.out.print("Enter the number of elements in the first linked list: ");
        int n1 = scanner.nextInt();
        System.out.print("Enter the elements of the first linked list: ");
        for (int i = 0; i < n1; i++) {
            list1.addAtEnd(scanner.nextInt());
        }

        System.out.print("Enter the number of elements in the second linked list: ");
        int n2 = scanner.nextInt();
        System.out.print("Enter the elements of the second linked list: ");
        for (int i = 0; i < n2; i++) {
            list2.addAtEnd(scanner.nextInt());
        }

        scanner.close();

        String result = LinkedList.compareLists(list1, list2);
        System.out.println(result);
    }
}
