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
    TreeNode findLCA(TreeNode root, int n1, int n2) {
        if (root == null) {
            return null;
        }

        if (root.val > n1 && root.val > n2) {
            return findLCA(root.left, n1, n2);
        }

        if (root.val < n1 && root.val < n2) {
            return findLCA(root.right, n1, n2);
        }

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
