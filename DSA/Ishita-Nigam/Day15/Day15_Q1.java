import java.util.Scanner;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }
}

public class Day15_Q1 {

    public static int height(TreeNode root) {
        if (root == null) {
            return -1;
        }

        int leftHeight = height(root.left);
        int rightHeight = height(root.right);

        return Math.max(leftHeight, rightHeight) + 1;
    }

    public static TreeNode buildTree(int n, int[][] nodes) {
        if (n == 0) {
            return null;
        }

        TreeNode[] treeNodes = new TreeNode[n];
        for (int i = 0; i < n; i++) {
            treeNodes[i] = new TreeNode(nodes[i][0]);
        }

        for (int i = 0; i < n; i++) {
            if (nodes[i][1] != -1) {
                treeNodes[i].left = treeNodes[nodes[i][1]];
            }
            if (nodes[i][2] != -1) {
                treeNodes[i].right = treeNodes[nodes[i][2]];
            }
        }

        return treeNodes[0];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of nodes in the tree: ");
        int n = scanner.nextInt();

        int[][] nodes = new int[n][3];
        System.out.println("Enter the nodes in the format: value left_index right_index (-1 for no child):");
        for (int i = 0; i < n; i++) {
            nodes[i][0] = scanner.nextInt();
            nodes[i][1] = scanner.nextInt();
            nodes[i][2] = scanner.nextInt();
        }

        TreeNode root = buildTree(n, nodes);
        System.out.println("Height of the binary tree: " + height(root));

        scanner.close();
    }
}
