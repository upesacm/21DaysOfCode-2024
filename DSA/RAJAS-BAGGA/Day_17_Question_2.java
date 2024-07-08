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

public class Day_17_Question_2 {
    
    public static void inOrder(TreeNode root) {
        
        if (root == null)
            return;
        
        inOrder(root.left);
        System.out.printf("%d ", root.val);
        inOrder(root.right);
        
    }
    
    public static TreeNode insertNode(TreeNode root, int val) {
        if (root == null)
            return new TreeNode(val);
        
        else if (val < root.val)
            root.left = insertNode(root.left, val);
        else if (val > root.val)
            root.right = insertNode(root.right, val);
        
        return root;
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(4);
        TreeNode n1 = new TreeNode(2);
        TreeNode n2 = new TreeNode(7);
        TreeNode n3 = new TreeNode(1);
        TreeNode n4 = new TreeNode(3);
        
        root.left = n1;
        root.right = n2;
        n2.left = n3;
        n2.right = n4;
        inOrder(root);
        System.out.println();
        root = insertNode(root, 5);
        inOrder(root);
        
    }
}
