class TreeNode {
    int value;
    TreeNode left;
    TreeNode right;

    TreeNode(int value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

public class BinaryTree {

    public static int heightOfBinaryTree(TreeNode root) {
        if (root == null) {
            return -1; // Return -1 for the height of an empty tree, so the height of a tree with a single node is 0
        }

        int leftHeight = heightOfBinaryTree(root.left);
        int rightHeight = heightOfBinaryTree(root.right);

        return Math.max(leftHeight, rightHeight) + 1;
    }

    public static void main(String[] args) {
        // Creating the binary tree from the example
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(2);
        root.right = new TreeNode(5);
        root.left.left = new TreeNode(1);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(6);

        // Calculate the height of the binary tree
        System.out.println(heightOfBinaryTree(root)); // Output: 2
    }
}

