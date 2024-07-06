class Node {
    int data;
    Node left, right;

    public Node(int item) {
        data = item;
        left = right = null;
    }
}

class Day15_que1 {
    Node root;

    int height(Node node) {
        if (node == null) {
            return -1; 
        } else {
            int leftHeight = height(node.left);
            int rightHeight = height(node.right);

            return Math.max(leftHeight, rightHeight) + 1;
        }
    }

    public static void main(String[] args) {

        Day15_que1 tree = new Day15_que1();

        // Creating the tree as per the example provided
        tree.root = new Node(3);
        tree.root.left = new Node(2);
        tree.root.right = new Node(5);
        tree.root.left.left = new Node(1);
        tree.root.right.left = new Node(4);
        tree.root.right.right = new Node(6);

        System.out.println("Height of the tree is : " + tree.height(tree.root));
    }
}
