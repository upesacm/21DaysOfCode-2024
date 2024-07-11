import java.util.*;

class TreeNode {
    int data;
    TreeNode left, right;

    public TreeNode(int item) {
        data = item;
        left = right = null;
    }
}

class Pair {
    TreeNode node;
    int hd;

    Pair(TreeNode n, int h) {
        node = n;
        hd = h;
    }
}

public class BinaryTree {
    TreeNode root;

    public List<Integer> topView(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        // Queue for BFS traversal
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, 0));

        // TreeMap to store the first node at each horizontal distance
        TreeMap<Integer, Integer> hdNodeMap = new TreeMap<>();

        while (!q.isEmpty()) {
            Pair temp = q.poll();
            TreeNode node = temp.node;
            int hd = temp.hd;

            // If this horizontal distance is not seen before, add the node
            if (!hdNodeMap.containsKey(hd)) {
                hdNodeMap.put(hd, node.data);
            }

            if (node.left != null) {
                q.add(new Pair(node.left, hd - 1));
            }

            if (node.right != null) {
                q.add(new Pair(node.right, hd + 1));
            }
        }

        // Extracting the top view nodes from the TreeMap
        List<Integer> topViewNodes = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : hdNodeMap.entrySet()) {
            topViewNodes.add(entry.getValue());
        }

        return topViewNodes;
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

        System.out.println(tree.topView(tree.root)); // Output: [4, 2, 1, 3, 7]
    }
}
