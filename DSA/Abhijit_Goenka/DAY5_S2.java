/*
  Create a function to compare two singly linked lists and determine if they are identical.

Inputs:
Two singly linked lists.
Output:
"identical" if the lists are the same, otherwise "different".
Example:

Linked list 1: 1 -> 2 -> 3

Linked list 2: 1 -> 2 -> 3

Output: identical
 */
import java.util.*; 
class DAY5_S2 { 
	Node head; 
	class Node { 
		int data; 
		Node next; 
		Node(int d) 
		{ 
			data = d; 
			next = null; 
		} 
	} 
	boolean areIdentical(DAY5_S2 listb) 
	{ 
		Node a = this.head, b = listb.head; 
		while (a != null && b != null) { 
			if (a.data != b.data) 
				return false;
			a = a.next; 
			b = b.next; 
		} 
		return (a == null && b == null); 
	} 
	void push(int new_data) 
	{ 
		Node new_node = new Node(new_data); 

		new_node.next = head; 
		head = new_node; 
	} 
	public static void main(String args[]) 
	{ 
		DAY5_S2 llist1 = new DAY5_S2(); 
		DAY5_S2 llist2 = new DAY5_S2(); 

		llist1.push(1); 
		llist1.push(2); 
		llist1.push(3); 

		llist2.push(1); 
		llist2.push(2); 
		llist2.push(3); 

		// Function call 
		if (llist1.areIdentical(llist2) == true) 
			System.out.println("Identical "); 
		else
			System.out.println("Not identical "); 
	} 
} 
