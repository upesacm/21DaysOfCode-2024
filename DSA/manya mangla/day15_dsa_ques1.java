class TreeNode {
    int value;
    TreeNode left;
    TreeNode right;

    TreeNode(int value) {
        this.value = value;
        left = null;
        right = null;
    }
}

public class BinaryTree {
    public static int heightOfBinaryTree(TreeNode root) {
        // Base case: if the tree is empty, the height is -1
        if (root == null) {
            return -1;
        }

        // Recursively find the height of the left and right subtrees
        int leftHeight = heightOfBinaryTree(root.left);
        int rightHeight = heightOfBinaryTree(root.right);

        // The height of the tree is the maximum of the heights of the subtrees, plus one
        return Math.max(leftHeight, rightHeight) + 1;
    }

    public static void main(String[] args) {
        // Constructing the binary tree
        //     3
        //    / \
        //   2   5
        //  /   / \
        // 1   4   6

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(1);
        root.right = new TreeNode(5);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(6);

        // Calculating the height of the tree
        System.out.println(heightOfBinaryTree(root));  // Output: 2
    }
}
