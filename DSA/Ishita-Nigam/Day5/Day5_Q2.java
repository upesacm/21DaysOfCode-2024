import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class Day5_Q2 {
    public static String compareLists(ListNode head1, ListNode head2) {
        while (head1 != null && head2 != null) {
            if (head1.val != head2.val) {
                return "different";
            }
            head1 = head1.next;
            head2 = head2.next;
        }

        if (head1 == null && head2 == null) {
            return "identical";
        } else {
            return "different";
        }
    }
    public static ListNode createList() {
        Scanner scanner = new Scanner(System.in);
        ListNode head = null, current = null;
        System.out.println("Enter elements of the linked list (enter -1 to stop):");

        while (true) {
            int val = scanner.nextInt();
            if (val == -1) {
                break;
            }

            ListNode newNode = new ListNode(val);

            if (head == null) {
                head = newNode;
                current = head;
            } else {
                current.next = newNode;
                current = current.next;
            }
        }

        return head;
    }

    public static void main(String[] args) {
        System.out.println("Creating first linked list:");
        ListNode head1 = createList();

        System.out.println("Creating second linked list:");
        ListNode head2 = createList();

        // Comparing the two linked lists
        System.out.println("The lists are " + compareLists(head1, head2));
    }
}
