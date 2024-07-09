class TreeNode {
    int value;
    TreeNode left;
    TreeNode right;

    TreeNode(int value) {
        this.value = value;
        left = right = null;
    }
}

public class BST {
    public TreeNode findLCA(TreeNode root, TreeNode node1, TreeNode node2) {
        TreeNode current = root;
        while (current != null) {
            if (node1.value < current.value && node2.value < current.value) {
                current = current.left;
            } else if (node1.value > current.value && node2.value > current.value) {
                current = current.right;
            } else {
                return current;
            }
        }
        return null;  // If there's no LCA (shouldn't happen in a valid BST with both nodes present)
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(20);
        root.left = new TreeNode(10);
        root.right = new TreeNode(30);
        root.left.left = new TreeNode(5);
        root.left.right = new TreeNode(15);
        root.right.left = new TreeNode(25);
        root.right.right = new TreeNode(35);

        TreeNode node1 = root.left.left;  // Node with value 5
        TreeNode node2 = root.right;      // Node with value 30

        BST bst = new BST();
        TreeNode lca = bst.findLCA(root, node1, node2);
        System.out.println("LCA value: " + (lca != null ? lca.value : "No LCA found"));
    }
}
