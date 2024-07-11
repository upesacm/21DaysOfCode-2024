import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int item) {
        val = item;
        left = right = null;
    }
}

class BinaryTree {
    TreeNode root;
    public List<Integer> topView(TreeNode root) {
        class NodeLevel {
            TreeNode node;
            int level;
            NodeLevel(TreeNode node, int level) {
                this.node = node;
                this.level = level;
            }
        }

        Map<Integer, Integer> topViewMap = new TreeMap<>();
        Queue<NodeLevel> queue = new LinkedList<>();
        if (root == null) {
            return new ArrayList<>();
        }
      
        queue.add(new NodeLevel(root, 0));
        while (!queue.isEmpty()) {
            NodeLevel temp = queue.poll();
            if (!topViewMap.containsKey(temp.level)) {
                topViewMap.put(temp.level, temp.node.val);
            }
            if (temp.node.left != null) {
                queue.add(new NodeLevel(temp.node.left, temp.level - 1));
            }
            if (temp.node.right != null) {
                queue.add(new NodeLevel(temp.node.right, temp.level + 1));
            }
        }
        List<Integer> result = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : topViewMap.entrySet()) {
            result.add(entry.getValue());
        }
        return result;
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new TreeNode(1);
        tree.root.left = new TreeNode(2);
        tree.root.right = new TreeNode(3);
        tree.root.left.left = new TreeNode(4);
        tree.root.left.right = new TreeNode(5);
        tree.root.right.left = new TreeNode(6);
        tree.root.right.right = new TreeNode(7);
        List<Integer> topView = tree.topView(tree.root);
        System.out.println("Top view of the binary tree:");
        for (int val : topView) {
            System.out.print(val + " ");
        }
    }
}
