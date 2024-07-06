import java.util.Scanner;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class BinaryTreeHeight {
    public static int heightOfTree(TreeNode root) {
        if (root == null) {
            return -1; // return -1 for empty tree
        } else {
            int leftHeight = heightOfTree(root.left);
            int rightHeight = heightOfTree(root.right);
            return Math.max(leftHeight, rightHeight) + 1;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        TreeNode[] nodes = new TreeNode[n];
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            nodes[i] = new TreeNode(val);
        }
        for (int i = 0; i < n - 1; i++) {
            int parent = scanner.nextInt();
            int child = scanner.nextInt();
            if (parent > n || parent < 0 || child > n || child < 0) {
                System.out.println("Invalid input");
                return;
            }
            if (nodes[parent - 1] != null) {
                if (nodes[parent - 1].left == null) {
                    nodes[parent - 1].left = nodes[child - 1];
                } else {
                    nodes[parent - 1].right = nodes[child - 1];
                }
            }
        }
        scanner.close();

        TreeNode root = nodes[0];
        System.out.println(heightOfTree(root));
    }
}

// For sample input
// Give the input like below and the output will be 2
//     6
//     3
//     2
//     5
//     1
//     4
//     6
//     1 2
//     1 3
//     4 5
//     3 5
//     3 6
