import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Main {
    public static List<Integer> topView(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        Map<Integer, Integer> map = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        Queue<Integer> horizontalDistanceQueue = new LinkedList<>();

        queue.add(root);
        horizontalDistanceQueue.add(0);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            int horizontalDistance = horizontalDistanceQueue.poll();

            if (!map.containsKey(horizontalDistance)) {
                map.put(horizontalDistance, node.val);
            }

            if (node.left!= null) {
                queue.add(node.left);
                horizontalDistanceQueue.add(horizontalDistance - 1);
            }

            if (node.right!= null) {
                queue.add(node.right);
                horizontalDistanceQueue.add(horizontalDistance + 1);
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int i = Collections.min(map.keySet()); i <= Collections.max(map.keySet()); i++) {
            result.add(map.get(i));
        }

        return result;
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
        System.out.println(result);
    }
}
