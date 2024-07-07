import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class Day16_Q1 {

    public static List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        postorderHelper(root, result);
        return result;
    }

    private static void postorderHelper(TreeNode node, List<Integer> result) {
        if (node == null) {
            return;
        }
        // Traverse left subtree
        postorderHelper(node.left, result);
        // Traverse right subtree
        postorderHelper(node.right, result);
        // Visit root node
        result.add(node.val);
    }

    public static void main(String[] args) {
        // Example binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        List<Integer> postorder = postorderTraversal(root);
        System.out.println(postorder); // Output: [4, 5, 2, 3, 1]
    }
}
