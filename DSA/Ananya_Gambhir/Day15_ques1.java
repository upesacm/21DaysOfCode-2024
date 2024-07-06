import java.util.Scanner;
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
public class Day15_ques1 {
    public static int height(TreeNode root) {
        if (root == null) {
            return -1;  
        }
        int leftHeight = height(root.left);
        int rightHeight = height(root.right);

        return Math.max(leftHeight, rightHeight) + 1;
    }

    public static TreeNode buildTree(Scanner scanner) {
        System.out.print("Enter node value (or 'null' for no node): ");
        String input = scanner.next();

        if (input.equals("null")) {
            return null;
        }

        int value = Integer.parseInt(input);
        TreeNode node = new TreeNode(value);

        System.out.println("Entering left child of " + value);
        node.left = buildTree(scanner);

        System.out.println("Entering right child of " + value);
        node.right = buildTree(scanner);
        return node;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Building the binary tree:");
        TreeNode root = buildTree(scanner);

        int treeHeight = height(root);
        System.out.println("The height of the binary tree is: " + treeHeight);

        scanner.close();
    }
}
