//Question-2
//Author - Ayush Dey

import java.util.Scanner;

class ListNode {
    int value;
    ListNode next;

    public ListNode(int value) {
        this.value = value;
        this.next = null;
    }
}

public class Q2 {
    // Function to compare two linked lists
    static boolean areIdentical(ListNode head1, ListNode head2) {
        while (head1 != null && head2 != null) {
            if (head1.value != head2.value) {
                return false; // Values are different, lists are not identical
            }
            head1 = head1.next;
            head2 = head2.next;
        }
        // If both lists are empty or reached the end simultaneously, they are identical
        return head1 == null && head2 == null;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ListNode list1 = null;
        ListNode list2 = null;

        System.out.println("Enter elements for linked list 1 (enter -1 to stop):");
        int value;
        while ((value = scanner.nextInt()) != -1) {
            ListNode newNode = new ListNode(value);
            if (list1 == null) {
                list1 = newNode;
            } else {
                ListNode temp = list1;
                while (temp.next != null) {
                    temp = temp.next;
                }
                temp.next = newNode;
            }
        }

        System.out.println("Enter elements for linked list 2 (enter -1 to stop):");
        while ((value = scanner.nextInt()) != -1) {
            ListNode newNode = new ListNode(value);
            if (list2 == null) {
                list2 = newNode;
            } else {
                ListNode temp = list2;
                while (temp.next != null) {
                    temp = temp.next;
                }
                temp.next = newNode;
            }
        }

        boolean result = areIdentical(list1, list2);
        System.out.println("Output: " + (result ? "identical" : "different"));
    }
}
