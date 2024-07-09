import java.util.*;

class MyTree {
    int data;
    MyTree left, right;

    MyTree(int data) {
        this.data = data;
        this.left = this.right = null;
    }
}

class Day18_08July_Ques1 {
    public static List<Integer> topView(MyTree root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        // Map to store the topmost node at each horizontal distance
        Map<Integer, Integer> topViewMap = new TreeMap<>();
        // Queue to store nodes along with their horizontal distance
        Queue<Pair> queue = new LinkedList<>();

        queue.add(new Pair(root, 0));

        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            MyTree node = current.node;
            int hd = current.hd;

            // If horizontal distance is not in the map, add the node's data
            if (!topViewMap.containsKey(hd)) {
                topViewMap.put(hd, node.data);
            }

            // Add the left and right children to the queue with their respective horizontal distances
            if (node.left != null) {
                queue.add(new Pair(node.left, hd - 1));
            }
            if (node.right != null) {
                queue.add(new Pair(node.right, hd + 1));
            }
        }

        // Extract the values from the map in order of horizontal distances
        for (Map.Entry<Integer, Integer> entry : topViewMap.entrySet()) {
            result.add(entry.getValue());
        }

        return result;
    }

    public static void main(String[] args) {
        MyTree root = new MyTree(1);
        root.left = new MyTree(2);
        root.right = new MyTree(3);
        root.left.left = new MyTree(4);
        root.left.right = new MyTree(5);
        root.right.left = new MyTree(6);
        root.right.right = new MyTree(7);

        List<Integer> topViewResult = topView(root);
        System.out.println("Top View: " + topViewResult);
    }
}

class Pair {
    MyTree node;
    int hd;

    Pair(MyTree node, int hd) {
        this.node = node;
        this.hd = hd;
    }
}
