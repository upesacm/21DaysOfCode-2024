/* Question-1
Author - Ayush Dey*/

import java.util.Scanner;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Q1 {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        } else {
            int leftHeight = maxDepth(root.left);
            int rightHeight = maxDepth(root.right);
            return Math.max(leftHeight, rightHeight) + 1;
        }
    }

    public static void main(String[] args) {
        Q1 solution = new Q1();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the root node value:");
        int rootVal = scanner.nextInt();
        TreeNode root = new TreeNode(rootVal);

        System.out.println("Enter the left child of " + rootVal + " (or -1 for null):");
        int leftVal = scanner.nextInt();
        if (leftVal!= -1) {
            root.left = new TreeNode(leftVal);
        }

        System.out.println("Enter the right child of " + rootVal + " (or -1 for null):");
        int rightVal = scanner.nextInt();
        if (rightVal!= -1) {
            root.right = new TreeNode(rightVal);
        }

        while (true) {
            System.out.println("Enter the parent node value:");
            int parentVal = scanner.nextInt();
            if (parentVal == -1) {
                break;
            }

            TreeNode parentNode = findNode(root, parentVal);
            if (parentNode == null) {
                System.out.println("Node not found. Try again.");
                continue;
            }

            System.out.println("Enter the left child of " + parentVal + " (or -1 for null):");
            int leftChildVal = scanner.nextInt();
            if (leftChildVal!= -1) {
                parentNode.left = new TreeNode(leftChildVal);
            }

            System.out.println("Enter the right child of " + parentVal + " (or -1 for null):");
            int rightChildVal = scanner.nextInt();
            if (rightChildVal!= -1) {
                parentNode.right = new TreeNode(rightChildVal);
            }
        }

        int height = solution.maxDepth(root);
        System.out.println("Height of the tree: " + height);
    }

    private static TreeNode findNode(TreeNode root, int val) {
        if (root == null) {
            return null;
        }
        if (root.val == val) {
            return root;
        }
        TreeNode leftNode = findNode(root.left, val);
        if (leftNode!= null) {
            return leftNode;
        }
        return findNode(root.right, val);
    }
}