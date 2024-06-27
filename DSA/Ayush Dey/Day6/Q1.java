//Question-1
//Author - Ayush Dey

//My approach : The hasCycle method is using a HashSet to keep track of all the nodes it
//has seen. If it encounters a node that is already in the set, it returns true indicating a cycle.

import java.util.HashSet;
import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class Q1 {

    public static boolean hasCycle(ListNode head) {
        HashSet<Integer> valuesSeen = new HashSet<>();
        ListNode current = head;
        
        while (current != null) {
            if (valuesSeen.contains(current.val)) {
                return true; // Cycle detected based on repeated value
            }
            valuesSeen.add(current.val);
            current = current.next;
        }
        return false; // No cycle found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of nodes: ");
        int n = scanner.nextInt();

        System.out.println("Enter the values of the nodes:");
        ListNode dummy = new ListNode(-1);
        ListNode curr = dummy;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            curr.next = new ListNode(val);
            curr = curr.next;
        }

        boolean hasCycle = hasCycle(dummy.next);
        System.out.println("Output: " + (hasCycle ? "cycle" : "no cycle"));
    }
}
