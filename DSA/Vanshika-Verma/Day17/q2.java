import java.util.Scanner;

class TreeNode {
    int val;
    TreeNode l;
    TreeNode r;
    TreeNode(int x) 
    {
        val = x;
    }
}
public class day17 {
    public static TreeNode ins(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val) ;
        }
        if (val < root.val) 
        {
            root.l = ins(root.l, val);
        } 
        else if (val > root.val) {
            root.r = ins(root.r, val) ;
        }
        return root;
    }
    public static void Trav(TreeNode root) 
    {
        if (root != null) 
        {
            Trav(root.l);
            System.out.print(root.val + " ") ;
            Trav(root.r);
        }
    }
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        TreeNode root = new TreeNode(4);
        root.l = new TreeNode(2);
        root.r = new TreeNode(7);
        root.l.l = new TreeNode(1);
        root.l.r = new TreeNode(3);
        System.out.print("Enter the value to insert: ");
        int valins = sc.nextInt();
        root = ins(root, valins);
        System.out.print("Updated BST (inorder traversal): ") ;
        Trav(root);
    }
}
