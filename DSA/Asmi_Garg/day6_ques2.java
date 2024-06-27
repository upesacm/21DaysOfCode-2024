import java.util.Scanner;

class ListNode {
    int value;
    ListNode next;

    ListNode(int value) {
        this.value = value;
        this.next = null;
    }
}

public class LinkedListMergePointFinder {

    public static int findMergePoint(ListNode head1, ListNode head2) {
        int len1 = getLength(head1);
        int len2 = getLength(head2);

        if (len1 > len2) {
            head1 = advanceListBy(head1, len1 - len2);
        } else {
            head2 = advanceListBy(head2, len2 - len1);
        }

        while (head1 != null && head2 != null) {
            if (head1 == head2) {
                return head1.value;
            }
            head1 = head1.next;
            head2 = head2.next;
        }

        return -1; 
    }

    private static int getLength(ListNode head) {
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }

    private static ListNode advanceListBy(ListNode head, int steps) {
        while (steps > 0 && head != null) {
            head = head.next;
            steps--;
        }
        return head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the linked list 1 in the format (e.g., 1 -> 2 -> 3):");
        String input1 = scanner.nextLine();
        ListNode head1 = createLinkedList(input1);

        System.out.println("Enter the linked list 2 in the format (e.g., 4 -> 5 -> 3):");
        String input2 = scanner.nextLine();
        ListNode head2 = createLinkedList(input2);

        System.out.println("Enter the merge value (common node value):");
        int mergeValue = scanner.nextInt();

        // Create a common node for both lists
        ListNode mergeNode = new ListNode(mergeValue);

        // Attach merge node to the end of both lists
        attachMergeNode(head1, mergeNode);
        attachMergeNode(head2, mergeNode);

        int mergePoint = findMergePoint(head1, head2);
        if (mergePoint != -1) {
            System.out.println("The merge point value is: " + mergePoint);
        } else {
            System.out.println("There is no merge point.");
        }

        scanner.close();
    }

    private static ListNode createLinkedList(String input) {
        String[] parts = input.split("->");
        ListNode head = new ListNode(Integer.parseInt(parts[0].trim()));
        ListNode current = head;

        for (int i = 1; i < parts.length; i++) {
            current.next = new ListNode(Integer.parseInt(parts[i].trim()));
            current = current.next;
        }

        return head;
    }

    private static void attachMergeNode(ListNode head, ListNode mergeNode) {
        if (head == null)
            return;

        ListNode current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = mergeNode;
    }
}
