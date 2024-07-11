public class Day_15_Q1 {
    public static int getHeight(TreeNode root) {
        if (root == null) {return -1;}

        int left = getHeight(root.left);
        int right = getHeight(root.right);

        return Math.max(left, right) + 1;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(1);
        root.right = new TreeNode(5);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(6);

        System.out.println(getHeight(root));
    }
}

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