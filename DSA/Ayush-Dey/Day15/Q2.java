// Question-2
// Author - Ayush Dey

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Q2 {
    public List<Integer> levelOrder(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            result.add(node.val);

            if (node.left != null) {
                queue.offer(node.left);
            }
            if (node.right != null) {
                queue.offer(node.right);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Q2 solution = new Q2();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the root node value:");
        int rootVal = scanner.nextInt();
        TreeNode root = new TreeNode(rootVal);

        System.out.println("Enter the left child of " + rootVal + " (or -1 for null):");
        int leftVal = scanner.nextInt();
        if (leftVal != -1) {
            root.left = new TreeNode(leftVal);
        }

        System.out.println("Enter the right child of " + rootVal + " (or -1 for null):");
        int rightVal = scanner.nextInt();
        if (rightVal != -1) {
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
            if (leftChildVal != -1) {
                parentNode.left = new TreeNode(leftChildVal);
            }

            System.out.println("Enter the right child of " + parentVal + " (or -1 for null):");
            int rightChildVal = scanner.nextInt();
            if (rightChildVal != -1) {
                parentNode.right = new TreeNode(rightChildVal);
            }
        }

        List<Integer> result = solution.levelOrder(root);
        System.out.println("Level order traversal: " + result);
    }

    private static TreeNode findNode(TreeNode root, int val) {
        if (root == null) {
            return null;
        }
        if (root.val == val) {
            return root;
        }
        TreeNode leftNode = findNode(root.left, val);
        if (leftNode != null) {
            return leftNode;
        }
        return findNode(root.right, val);
    }
}