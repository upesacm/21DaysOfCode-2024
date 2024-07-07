import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
        left = null;
        right = null;
    }
}

public class Day16_ques1 {

    public void postorderTraversal(TreeNode root) {
        postorderHelper(root);
    }

    private void postorderHelper(TreeNode node) {
        if (node == null) {
            return;
        }
        postorderHelper(node.left);
        postorderHelper(node.right);
        System.out.print(node.val + " ");
    }

    public static TreeNode buildTree() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the root value: ");
        int rootValue = scanner.nextInt();
        TreeNode root = new TreeNode(rootValue);

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();
            System.out.println("Enter left child of " + current.val + " (or -1 for no child): ");
            int leftValue = scanner.nextInt();
            if (leftValue != -1) {
                current.left = new TreeNode(leftValue);
                queue.add(current.left);
            }

            System.out.println("Enter right child of " + current.val + " (or -1 for no child): ");
            int rightValue = scanner.nextInt();
            if (rightValue != -1) {
                current.right = new TreeNode(rightValue);
                queue.add(current.right);
            }
        }
        scanner.close();
        return root;
    }

    public static void main(String[] args) {
        TreeNode root = buildTree();

        BinaryTreePostorderTraversal traversal = new BinaryTreePostorderTraversal();
        System.out.print("Postorder Traversal: ");
        traversal.postorderTraversal(root);
    }
}
