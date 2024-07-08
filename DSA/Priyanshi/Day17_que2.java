class Node {
    int data;
    Node left, right;

    Node(int v) {
        data = v;
        left = right = null;
    }
}

class Day17_que2 {

    public static Node insert(Node root, int value) {
        if (root == null) {
            return new Node(value);
        }

        if (value < root.data) {
            root.left = insert(root.left, value);
        } else if (value > root.data) {
            root.right = insert(root.right, value);
        }

        return root;
    }

    // Function to print inorder traversal of the BST
    public static void printInorder(Node node) {
        if (node == null)
            return;

        printInorder(node.left);
        System.out.print(node.data + " ");
        printInorder(node.right);
    }

    public static void main(String[] args) {
        Node root = new Node(4);
        root.left = new Node(2);
        root.right = new Node(7);
        root.left.left = new Node(1);
        root.left.right = new Node(3);

        System.out.println("Inorder traversal of original BST:");
        printInorder(root);
        System.out.println();

        int valueToInsert = 5;
        root = insert(root, valueToInsert);

        System.out.println("Inorder traversal of updated BST:");
        printInorder(root);
    }
}
