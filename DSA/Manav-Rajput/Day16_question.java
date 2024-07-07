import java.util.ArrayList;
import java.util.List;



public class BinaryTreeInorderTraversal {

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        inorderHelper(root, result);
        return result;
    }

    private void inorderHelper(TreeNode node, List<Integer> result) {
        if (node == null) {
            return;
        }
        inorderHelper(node.left, result);
        result.add(node.val);
        inorderHelper(node.right, result);
    }

    public static void main(String[] args) {
        // Create the binary tree from the example
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        BinaryTreeInorderTraversal solution = new BinaryTreeInorderTraversal();
        List<Integer> inorder = solution.inorderTraversal(root);
        System.out.println(inorder);  // Output: [4, 2, 5, 1, 3]
    }
}
