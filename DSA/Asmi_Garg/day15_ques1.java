import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
        left = right = null;
    }
}

public class BinaryTree {
    public int height(TreeNode root) {
        if (root == null) {
            return -1;
        } else {
            int leftHeight = height(root.left);
            int rightHeight = height(root.right);
            return Math.max(leftHeight, rightHeight) + 1;
        }
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.println("Height of the tree is: " + tree.height(root));
    }

    public List<Integer> levelOrderTraversal(TreeNode root) {
        throw new UnsupportedOperationException("Unimplemented method 'levelOrderTraversal'");
    }
}
