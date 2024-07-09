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
class DAY17_S2 
{
    public TreeNode insertIntoBST(TreeNode root, int val) 
    {
        if (root == null) 
        {
            return new TreeNode(val);
        }

        if (val < root.val) 
        {
            root.left = insertIntoBST(root.left, val);
        } else if (val > root.val) {
            root.right = insertIntoBST(root.right, val);
        }

        return root;
    }

    public static void main(String[] args) 
    {
        DAY17_S2 tree = new DAY17_S2();

        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);

        int valueToInsert = 5;

        TreeNode updatedRoot = tree.insertIntoBST(root, valueToInsert);

        printInOrder(updatedRoot);
    }

    public static void printInOrder(TreeNode root) 
    {
        if (root != null) 
        {
            printInOrder(root.left);
            System.out.print(root.val + " ");
            printInOrder(root.right);
        }
    }
}

