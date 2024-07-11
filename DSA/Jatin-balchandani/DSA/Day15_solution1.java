class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Day15_solution1 {
    public int height(TreeNode root) {
        if (root == null) {
            return -1; // Base case: if the node is null, the height is -1
        }

        // Recursively find the height of the left and right subtrees
        int leftHeight = height(root.left);
        int rightHeight = height(root.right);

        // The height of the current node is the maximum of the heights of its subtrees plus one
        return Math.max(leftHeight, rightHeight) + 1;
    }

    public static void main(String[] args) {
        Day15_solution1 sol = new Day15_solution1();

        // Create the binary tree from the example
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(2);
        root.right = new TreeNode(5);
        root.left.left = new TreeNode(1);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(6);

        // Calculate and print the height of the tree
        System.out.println("The height of the tree is: " + sol.height(root));
    }
}
