class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode(int val) {
        this.val = val;
    }
}

public class BSTLowestCommonAncestor {
    
    public static TreeNode lowestCommonAncestor(TreeNode root, int p, int q) {
        if (root == null) {
            return null;
        }
    
        if (p > root.val && q > root.val) {
            return lowestCommonAncestor(root.right, p, q);
        }
        if (p < root.val && q < root.val) {
            return lowestCommonAncestor(root.left, p, q);
        }
        return root;
    }
    
    public static TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        
        if (val < root.val) {
            root.left = insertIntoBST(root.left, val);
        } else if (val > root.val) {
            root.right = insertIntoBST(root.right, val);
        }
        
        return root;
    }
    
    public static void main(String[] args) {
        TreeNode root = null;
        int[] values = {20, 10, 30, 5, 15, 25, 35};
        
        for (int val : values) {
            root = insertIntoBST(root, val);
        }
        int node1 = 5;
        int node2 = 30;
        
        TreeNode lca = lowestCommonAncestor(root, node1, node2);
        
        if (lca != null) {
            System.out.println("The Lowest Common Ancestor of " + node1 + " and " + node2 + " is: " + lca.val);
        } else {
            System.out.println("LCA not found or one of the nodes doesn't exist in the tree.");
        }
    }
}
