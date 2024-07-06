class Node {
	int data;
	Node left, right;
	Node(int v)
	{
		data = v;
		left = right = null;
	}
}

class Day16_que1 {

	static void printPostorder(Node node)
	{
		if (node == null)
			return;

		printPostorder(node.left);

		printPostorder(node.right);

		System.out.print(node.data + " ");
	}

	public static void main(String[] args)
	{
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);

		System.out.println("Postorder traversal of binary tree is: ");
		printPostorder(root);
	}
}
