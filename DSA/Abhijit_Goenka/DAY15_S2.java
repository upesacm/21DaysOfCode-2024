import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode(int x) {
        val = x;
    }
}
class DAY15_S2 {

    public static List<Integer> levelOrder(TreeNode root) 
    {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            result.add(node.val);
            
            if (node.left != null) 
            {
                queue.add(node.left);
            }
            
            if (node.right != null) 
            {
                queue.add(node.right);
            }
        }
        return result;
    }
    public static void main(String[] args) 
    {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        List<Integer> traversalResult = levelOrder(root);
        System.out.println(traversalResult);
    }
}

