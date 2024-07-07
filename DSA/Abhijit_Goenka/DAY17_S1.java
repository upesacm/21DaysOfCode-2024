class TreeNode 
{
    int val;
    TreeNode left, right;

    TreeNode(int val) 
    {
        this.val = val;
        left = right = null;
    }
}
class DAY17_S1 
{
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) 
    {
        
        if (p.val > q.val) 
        {
            TreeNode temp = p;
            p = q;
            q = temp;
        }

        while (root != null) 
        {
            if (root.val < p.val) 
            {
                
                root = root.right;
            } 
            else if (root.val > q.val) 
            {
                
                root = root.left;
            } 
            else 
            {
                
                return root;
            }
        }

        return null; 
    }

    public static void main(String[] args) 
    {
        DAY17_S1 tree = new DAY17_S1();
        
        
        TreeNode root = new TreeNode(20);
        root.left = new TreeNode(10);
        root.right = new TreeNode(30);
        root.left.left = new TreeNode(5);
        root.left.right = new TreeNode(15);
        root.right.left = new TreeNode(25);
        root.right.right = new TreeNode(35);

        TreeNode node1 = root.left.left; 
        TreeNode node2 = root.right;     
        TreeNode lca = tree.lowestCommonAncestor(root, node1, node2);

        if (lca != null) 
        {
            System.out.println(lca.val);
        } else 
        {
            System.out.println("LCA not found");
        }
    }
}
