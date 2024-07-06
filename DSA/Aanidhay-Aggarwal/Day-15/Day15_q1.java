class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class BinaryTreeHeight {
    public int heightOfTree(TreeNode root) {
        if (root == null) {
            return -1; // return -1 for empty tree
        } else {
            int leftHeight = heightOfTree(root.left);
            int rightHeight = heightOfTree(root.right);
            return Math.max(leftHeight, rightHeight) + 1;
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(2);
        root.right = new TreeNode(5);
        root.left.left = new TreeNode(1);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(6);

        BinaryTreeHeight bt = new BinaryTreeHeight();
        System.out.println(bt.heightOfTree(root));  // Output: 2
    }
}
