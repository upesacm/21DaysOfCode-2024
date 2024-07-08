import java.util.Stack;

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


public class Day_18_Question_1 {
    
    static Stack<Integer> stack = new Stack<Integer>();
    
    public static void topView(TreeNode root) {
        TreeNode temp = root;
        while (temp != null) {
            stack.push(temp.val);
            temp = temp.left;
        }
        
        while (!stack.isEmpty())
            System.out.printf("%d ", stack.pop());
        
        while (root.right != null) {
            System.out.printf("%d ", root.right.val);
            root = root.right;
        }
        
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode n1 = new TreeNode(2);
        TreeNode n2 = new TreeNode(3);
        TreeNode n3 = new TreeNode(4);
        TreeNode n4 = new TreeNode(5);
        TreeNode n5 = new TreeNode(6);
        TreeNode n6 = new TreeNode(7);
        
        root.left = n1;
        root.right = n2;
        n1.left = n3;
        n1.right = n4;
        n2.left = n5;
        n2.right = n6;
        
        topView(root);
    }
}
