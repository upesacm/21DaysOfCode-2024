import java.util.*;
public class Day6_ques1 {
    Node head;

    static class Node {
        int value;
        Node next;

        Node(int d) {
            value=d;
            next=null;
        }
    }
    public boolean checkLoop() {
        Node first=head;
        Node second=head;

        while (first!=null&&first.next!=null) {
            first=first.next.next;
            second=second.next;

            if (first==second) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        Day6_ques1 linkedList=new Day6_ques1();
        System.out.print("Enter the number of nodes: ");
        int n=scanner.nextInt();
        if(n<=0) {
            System.out.println("The linked list must have at least one node.");
            return;
        }
        System.out.println("Enter the values for the nodes:");
        Node current=null;
        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            if (i == 0) {
                linkedList.head = new Node(value);
                current = linkedList.head;
            } else {
                current.next = new Node(value);
                current = current.next;
            }
        }
        System.out.print("Do you want to create a loop? (yes/no): ");
        String createLoop = scanner.next();

        if (createLoop.equalsIgnoreCase("yes")) {
            System.out.print("Enter the position (1 to " + n + ") to create a loop back to: ");
            int pos = scanner.nextInt();

            if (pos <= 0 || pos > n) {
                System.out.println("Invalid position for loop creation.");
                return;
            }

            Node loopNode = linkedList.head;
            for (int i = 1; i < pos; i++) {
                loopNode = loopNode.next;
            }
            current.next = loopNode;
        }

        boolean loop = linkedList.checkLoop();
        if (loop) {
            System.out.println("Cycle.");
        } else {
            System.out.println("No cycle.");
        }

        scanner.close();
    }
}
