// File: Day17_Q1.java

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

public class Day17_Q1 {
    // Function to find LCA of n1 and n2. 
    // The function assumes that both n1 and n2 are present in BST
    TreeNode findLCA(TreeNode root, int n1, int n2) {
        if (root == null) {
            return null;
        }
        
        // If both n1 and n2 are smaller than root, then LCA lies in left subtree
        if (root.val > n1 && root.val > n2) {
            return findLCA(root.left, n1, n2);
        }
        
        // If both n1 and n2 are greater than root, then LCA lies in right subtree
        if (root.val < n1 && root.val < n2) {
            return findLCA(root.right, n1, n2);
        }
        
        // If one key is present in the left subtree and the other is present in the right subtree,
        // then this node is the LCA
        return root;
    }

    public static void main(String[] args) {
        Day17_Q1 tree = new Day17_Q1();
        TreeNode root = new TreeNode(20);
        root.left = new TreeNode(10);
        root.right = new TreeNode(30);
        root.left.left = new TreeNode(5);
        root.left.right = new TreeNode(15);
        root.right.left = new TreeNode(25);
        root.right.right = new TreeNode(35);

        int n1 = 5;
        int n2 = 30;

        TreeNode lca = tree.findLCA(root, n1, n2);
        if (lca != null) {
            System.out.println("LCA of " + n1 + " and " + n2 + " is " + lca.val);
        } else {
            System.out.println("LCA does not exist");
        }
    }
}
