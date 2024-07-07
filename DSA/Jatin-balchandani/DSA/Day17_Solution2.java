public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class Day17_Solution2 {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            // If the tree is empty, return a new node with the given value
            return new TreeNode(val);
        }

        if (val < root.val) {
            // If the value to insert is less than the current node's value, go to the left subtree
            root.left = insertIntoBST(root.left, val);
        } else {
            // If the value to insert is greater than the current node's value, go to the right subtree
            root.right = insertIntoBST(root.right, val);
        }

        return root;
    }
}
