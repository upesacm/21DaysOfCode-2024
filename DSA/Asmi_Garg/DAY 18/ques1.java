import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) {
        val = x;
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

public class BinaryTreeTopView {
    public List<Integer> topView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Map<Integer, Integer> topViewMap = new TreeMap<>();
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(root, 0));

        while (!queue.isEmpty()) {
            Pair currentPair = queue.poll();
            TreeNode currentNode = currentPair.node;
            int hd = currentPair.hd;

            if (!topViewMap.containsKey(hd)) {
                topViewMap.put(hd, currentNode.val);
            }

            if (currentNode.left != null) {
                queue.add(new Pair(currentNode.left, hd - 1));
            }

            if (currentNode.right != null) {
                queue.add(new Pair(currentNode.right, hd + 1));
            }
        }

        for (int value : topViewMap.values()) {
            result.add(value);
        }

        return result;
    }

    public static void main(String[] args) {
        BinaryTreeTopView tree = new BinaryTreeTopView();
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        List<Integer> topView = tree.topView(root);
        System.out.println(topView);
    }
}
