public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class Day17_Solution1 {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while (root != null) {
            if (p.val < root.val && q.val < root.val) {
                // Both nodes are in the left subtree
                root = root.left;
            } else if (p.val > root.val && q.val > root.val) {
                // Both nodes are in the right subtree
                root = root.right;
            } else {
                // The current root is the LCA
                return root;
            }
        }
        return null; // This line should never be reached if p and q are in the tree
    }
}
