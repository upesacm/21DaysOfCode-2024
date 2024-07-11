public class Day6_solution2 {

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }

        ListNode pointerA = headA;
        ListNode pointerB = headB;

        // Traverse both lists. When one reaches the end, switch to the other list.
        // This ensures both pointers have traversed the same number of nodes.
        while (pointerA != pointerB) {
            pointerA = (pointerA == null) ? headB : pointerA.next;
            pointerB = (pointerB == null) ? headA : pointerB.next;
        }

        return pointerA;
    }

    public static void main(String[] args) {
        Day6_solution2 solution = new Day6_solution2();

        // Example linked list 1: 1 -> 2 -> 3
        ListNode list1 = new ListNode(1);
        list1.next = new ListNode(2);
        ListNode mergeNode = new ListNode(3);
        list1.next.next = mergeNode;

        // Example linked list 2: 4 -> 5
        ListNode list2 = new ListNode(4);
        list2.next = new ListNode(5);
        list2.next.next = mergeNode;  // Merge point is 3

        ListNode intersectionNode = solution.getIntersectionNode(list1, list2);
        if (intersectionNode != null) {
            System.out.println("The merge point value is: " + intersectionNode.val);  // Expected output: 3
        } else {
            System.out.println("No merge point found.");
        }
    }
}
