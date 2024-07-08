class TreeNode {
    int value;
    TreeNode left;
    TreeNode right;

    TreeNode(int value) {
        this.value = value;
        left = right = null;
    }
}

public class BST2 {
    public TreeNode insert(TreeNode root, int value) {
        if (root == null) {
            return new TreeNode(value);
        }

        if (value < root.value) {
            root.left = insert(root.left, value);
        } else if (value > root.value) {
            root.right = insert(root.right, value);
        }

        return root;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);

        BST2 bst = new BST2();
        root = bst.insert(root, 5);

        // Function to print the BST
        printInOrder(root);
    }

    public static void printInOrder(TreeNode node) {
        if (node != null) {
            printInOrder(node.left);
            System.out.print(node.value + " ");
            printInOrder(node.right);
        }
    }
}

