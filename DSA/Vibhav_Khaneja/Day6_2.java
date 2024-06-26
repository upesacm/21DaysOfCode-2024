class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Day6_2 {
    private static Node ConverArray(int[] arr) {
        if (arr.length == 0) {
            return null;
        }
        Node head = new Node(arr[0]);
        Node mover = head;

        for (int i = 1; i < arr.length; i++) {
            Node temp = new Node(arr[i]);
            mover.next = temp;
            mover = temp;
        }
        return head;
    }

    public static Node IntersectionPoint(Node head1, Node head2) {
        while (head2 != null) {
            Node temp = head1;
            while (temp != null) {
                if (temp == head2) {
                    return head2;
                }
                temp = temp.next;
            }
            head2 = head2.next;
        }
        return null;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3};
        Node head1 = ConverArray(arr1);

        int[] arr2 = {4, 5, 3};
        Node head2 = ConverArray(arr2);
        head2.next.next = head1.next.next; 

        Node intersectionNode = IntersectionPoint(head1, head2);
        if (intersectionNode == null) {
            System.out.println("No intersection point");
        } else {
            System.out.println("Intersection at point: " + intersectionNode.data);
        }
    }
}
