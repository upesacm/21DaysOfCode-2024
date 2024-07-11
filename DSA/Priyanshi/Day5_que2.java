class Day5_que2 
{
    static Node head1;
    static Node head2;

    static class Node 
    {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    // Function to compare two linked lists
    public static String compareLists(Node head1, Node head2) 
    {
        Node temp1 = head1;
        Node temp2 = head2;

        while (temp1 != null && temp2 != null) 
        {
            if (temp1.data != temp2.data) 
            {
                return "different";
            }
            temp1 = temp1.next;
            temp2 = temp2.next;
        }

        // Check if both lists reached the end
        if (temp1 == null && temp2 == null) 
        {
            return "identical";
        } 
        else 
        {
            return "different";
        }
    }

    //function to create a linked list from an array of values
    public static Node createLinkedList(int[] values) 
    {
        if (values.length == 0) return null;
        Node head = new Node(values[0]);
        Node current = head;
        for (int i = 1; i < values.length; i++) 
        {
            current.next = new Node(values[i]);
            current = current.next;
        }
        return head;
    }

    public static void main(String[] args) 
    {
        int[] values1 = {1, 2, 3};
        head1 = createLinkedList(values1);

        int[] values2 = {1, 2, 3};
        head2 = createLinkedList(values2);

        String result = compareLists(head1, head2);
        System.out.println("The linked lists are " + result);
    }
}
