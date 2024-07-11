import java.util.HashSet;
import java.util.Scanner;

public class Day6_que1 
{

    static Node head; 

    static class Node {
        int data;
        Node next;
        Node(int x) {
            data = x;
            next = null;
        }
    }

    static public void push(int new_data) {
        Node new_node = new Node(new_data);
        new_node.next = head;
        head = new_node;
    }

    static boolean detectLoop(Node h) {
        HashSet<Node> s = new HashSet<Node>();
        while (h != null) {
            if (s.contains(h))
                return true;
            s.add(h);
            h = h.next;
        }
        return false;
    }

    static void createLoop(int position) {
        if (position <= 0) return;
        Node temp = head;
        Node loopNode = null;
        int count = 1;
        while (temp.next != null) {
            if (count == position) {
                loopNode = temp;
            }
            temp = temp.next;
            count++;
        }
        if (loopNode != null) {
            temp.next = loopNode;
        }
    }

    public static void main(String[] args) {
        Day6_que1 obj = new Day6_que1();
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of elements in the linked list:");
        int n = sc.nextInt();
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            int data = sc.nextInt();
            obj.push(data);
        }

        System.out.println("Enter the position to create a loop (0 for no loop):");
        int loopPosition = sc.nextInt();
        if (loopPosition > 0) {
            createLoop(loopPosition);
        }

        if (detectLoop(head)) {
            System.out.println("Cycle");
        } else {
            System.out.println("No cycle");
        }

        sc.close();
    }
}
