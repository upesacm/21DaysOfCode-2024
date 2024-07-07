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

public class Day_17_Question_1 {
    public static TreeNode getLCA(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null)
            return null;
        
        int current = root.val;
        if (current < p.val && current < q.val)
            return getLCA(root.right, p, q);
        
        if (current > p.val && current > q.val)
            return getLCA(root.left, p, q);
        
        return root;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(20);
        TreeNode n1 = new TreeNode(10);
        TreeNode n2 = new TreeNode(30);
        TreeNode n3 = new TreeNode(5);
        TreeNode n4 = new TreeNode(15);
        TreeNode n5 = new TreeNode(25);
        TreeNode n6 = new TreeNode(35);
        
        root.left = n1;
        root.right = n2;
        n1.left = n3;
        n1.right = n4;
        n2.left = n5;
        n2.right = n6;
        
        System.out.println(getLCA(root, n3, n2).val);
    }
}
