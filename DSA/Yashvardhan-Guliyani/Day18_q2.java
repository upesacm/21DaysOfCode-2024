import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class Pair {
    TreeNode node;
    int hd;  
    
    Pair(TreeNode node, int hd) {
        this.node = node;
        this.hd = hd;
    }
}

public class BinaryTreeTopView {
    public static List<Integer> topView(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        
        Map<Integer, Integer> topViewMap = new TreeMap<>();
        Queue<Pair> queue = new LinkedList<>();
        
        queue.add(new Pair(root, 0));
        
        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            TreeNode node = pair.node;
            int hd = pair.hd;
            
            if (!topViewMap.containsKey(hd)) {
                topViewMap.put(hd, node.val);
            }
            
            if (node.left != null) {
                queue.add(new Pair(node.left, hd - 1));
            }
            
            if (node.right != null) {
                queue.add(new Pair(node.right, hd + 1));
            }
        }
        
        return new ArrayList<>(topViewMap.values());
    }

    public static void main(String[] args) {
      
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);
        
        List<Integer> result = topView(root);
        
        System.out.println("Top view of the binary tree: " + result);
    }
}
