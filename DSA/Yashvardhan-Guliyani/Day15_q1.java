class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode(int val) {
        this.val = val;
    }
}

public class BinaryTreeHeight {
    public static int treeHeight(TreeNode root) {
        if (root == null) {
            return -1;  
        }
        
        int leftHeight = treeHeight(root.left);
        int rightHeight = treeHeight(root.right);
        
        return Math.max(leftHeight, rightHeight) + 1;
    }
    
    public static void main(String[] args) {
        
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(1);
        root.right = new TreeNode(4);
        root.right.right = new TreeNode(6);
        
        int height = treeHeight(root);
        System.out.println("The height of the binary tree is: " + height);
    }
}
