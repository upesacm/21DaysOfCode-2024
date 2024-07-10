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

public class LCABinarySearchTree {

    static TreeNode findLCA(TreeNode root, TreeNode node1, TreeNode node2) {
        if (root == null) {
            return null;
        }
        if (node1.value < root.value && node2.value < root.value) {
            return findLCA(root.left, node1, node2);
        }
        if (node1.value > root.value && node2.value > root.value) {
            return findLCA(root.right, node1, node2);
        }
        return root;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(20);
        root.left = new TreeNode(10);
        root.right = new TreeNode(30);
        root.left.left = new TreeNode(5);
        root.left.right = new TreeNode(15);
        root.right.left = new TreeNode(25);
        root.right.right = new TreeNode(35);
        TreeNode node1 = root.left.left; 
        TreeNode node2 = root.right; 

        TreeNode lca = findLCA(root, node1, node2);

        if (lca != null) {
            System.out.println("Lowest Common Ancestor: " + lca.value);
        } else {
            System.out.println("Lowest Common Ancestor not found.");
        }
    }
}
