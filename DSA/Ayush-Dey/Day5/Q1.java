//Question-1
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

public class Q1 {
    // Function to reverse the linked list iteratively
    static ListNode reverse(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        ListNode next;

        while (current != null) {
            next = current.next;
            current.next = prev; // Reverse the link
            prev = current;
            current = next;
        }

        return prev; // New head of the reversed list
    }

    // Function to print the linked list
    static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.value);
            if (head.next != null) {
                System.out.print(" -> "); 
            }
            head = head.next;
        }
        System.out.println(); // Move to the next line
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ListNode head = null;

        System.out.println("Enter linked list elements (enter -1 to stop):");
        int value;
        while ((value = scanner.nextInt()) != -1) {
            ListNode newNode = new ListNode(value);
            if (head == null) {
                head = newNode; // Initialize the head if it's null
            } else {
                ListNode temp = head;
                while (temp.next != null) {
                    temp = temp.next; // Traversing to the end of the list
                }
                temp.next = newNode; // Add the new node at the end
            }
        }

        System.out.println("Original Linked list:");
        printList(head);

        head = reverse(head); // Reverse the linked list

        System.out.println("Reversed linked list:");
        printList(head);
    }
}
