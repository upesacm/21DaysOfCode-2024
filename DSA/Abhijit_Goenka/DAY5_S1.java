/*Given a singly linked list, write a function to print the elements in reverse order.

Inputs:
A singly linked list.
Output:
The elements of the list in reverse order.
Example:

Linked list: 1 -> 2 -> 3

Output: 3 2 1
 */
class DAY5_S1
{
	Node head; 

	class Node
	{
		int data;
		Node next;
		Node(int d) {data = d; next = null; }
	}
	void printReverse(Node head)
	{
		if (head == null) return;

		printReverse(head.next);
		System.out.print(head.data+" ");
	}
	public void push(int new_data)
	{
		Node new_node = new Node(new_data);
		new_node.next = head;
		head = new_node;
	}
	public static void main(String args[])
	{
		
		DAY5_S1 llist = new DAY5_S1();
		llist.push(4);
		llist.push(3);
		llist.push(2);
		llist.push(1);

		llist.printReverse(llist.head);
	}
}

