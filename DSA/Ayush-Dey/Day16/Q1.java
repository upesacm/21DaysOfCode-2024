// Question - 1
// Author - Ayush Dey

import java.util.Scanner;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Q1 {
    public static void postorderTraversal(TreeNode root) {
        if (root == null) return;
        postorderTraversal(root.left);
        postorderTraversal(root.right);
        System.out.print(root.val + " ");
    }

    public static TreeNode createTreeFromUserInput() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int numNodes = scanner.nextInt();

        TreeNode root = null;
        for (int i = 0; i < numNodes; i++) {
            System.out.print("Enter node " + (i + 1) + " value: ");
            int val = scanner.nextInt();

            if (root == null) {
                root = new TreeNode(val);
            } else {
                TreeNode curr = root;
                while (true) {
                    System.out.print("Enter left (0) or right (1) child for node " + curr.val + ": ");
                    int childType = scanner.nextInt();

                    if (childType == 0) {
                        if (curr.left == null) {
                            curr.left = new TreeNode(val);
                            break;
                        } else {
                            curr = curr.left;
                        }
                    } else {
                        if (curr.right == null) {
                            curr.right = new TreeNode(val);
                            break;
                        } else {
                            curr = curr.right;
                        }
                    }
                }
            }
        }

        return root;
    }

    public static void main(String[] args) {
        TreeNode root = createTreeFromUserInput();
        System.out.print("Postorder Traversal: ");
        postorderTraversal(root);
    }
}