class TreeNode {
    int val;
    TreeNode l;
    TreeNode r;

    TreeNode(int x) {
        val = x;
    }
}
public class day17 {
    public static TreeNode low(TreeNode root, TreeNode p, TreeNode q) 
    {
        if (root == null) 
        {
            return null;
        }
        if (p.val < root.val && q.val < root.val) {
            return low(root.l, p, q);
        }
        if (p.val > root.val && q.val > root.val) {
            return low(root.r, p, q);
        }
        return root;
    }
    public static void main(String[] args) 
    {
        TreeNode root = new TreeNode(20);
        root.l = new TreeNode(10);
        root.r = new TreeNode(30);
        root.l.l = new TreeNode(5);
        root.l.r = new TreeNode(15);
        root.r.l = new TreeNode(25);
        root.r.r = new TreeNode(35);
        TreeNode p = root.l.l;
        TreeNode q = root.r;  
        TreeNode lca = low(root, p, q);
        System.out.println(lca.val);
    }
}
