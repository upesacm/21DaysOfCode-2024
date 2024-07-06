class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Day_15_Question_1 {
    static int count = 0;
    static int max = 0;
    public static int maxHeight(TreeNode root) {
        if (root == null)
            return 0;
        traverse(root);
        return max;
    }
    
    public static void traverse(TreeNode root) {
        if (root == null)
            return;
        
        ++count;
        traverse(root.left);
        traverse(root.right);
        max = Math.max(max, count);
        --count;
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        TreeNode n1 = new TreeNode(2);
        TreeNode n2 = new TreeNode(5);
        TreeNode n3 = new TreeNode(1);
        TreeNode n4 = new TreeNode(4);
        TreeNode n5 = new TreeNode(6);
        
        root.left = n1;
        root.right = n2;
        n1.left = n3;
        n2.left = n4;
        n2.right = n5;
        System.out.println(maxHeight(root));
    }
}
