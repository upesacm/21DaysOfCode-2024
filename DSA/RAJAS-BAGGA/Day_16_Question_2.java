
import java.util.*;

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

public class Day_16_Question_2 {
    static List<Integer> tree = new ArrayList<>();
    public static List<Integer> inOrder(TreeNode root) {
        traverse(root);
        return tree;
    }
    public static void traverse(TreeNode root) {
        
        if (root == null)
            return;
        
        traverse(root.left);
        tree.add(root.val);
        traverse(root.right);
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode n1 = new TreeNode(2);
        TreeNode n2 = new TreeNode(3);
        TreeNode n3 = new TreeNode(4);
        TreeNode n4 = new TreeNode(5);
        
        root.left = n1;
        root.right = n2;
        n1.left = n3;
        n1.right = n4;
        System.out.println(inOrder(root));
    }
}
