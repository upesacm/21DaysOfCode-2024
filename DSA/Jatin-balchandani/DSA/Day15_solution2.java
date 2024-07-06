import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Day15_Solution2 {
    public List<Integer> levelOrder(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            result.add(node.val);

            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Day15_Solution2 sol = new Day15_Solution2();

        // Create the binary tree from the example
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        // Perform level order traversal and print the result
        List<Integer> traversalResult = sol.levelOrder(root);
        System.out.println("Level order traversal: " + traversalResult);
    }
}
