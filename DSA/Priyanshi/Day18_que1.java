import java.util.*;
class Node {
    int data;
    Node left, right;

    Node(int v) {
        data = v;
        left = right = null;
    }
}

class QueueNode {
    Node node;
    int hd;

    QueueNode(Node n, int h) {
        node = n;
        hd = h;
    }
}

class Day18_que1 {

    public static List<Integer> topView(Node root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        // Map to store the first node at each horizontal distance
        Map<Integer, Integer> topViewMap = new TreeMap<>();
        // Queue to perform level-order traversal
        Queue<QueueNode> queue = new LinkedList<>();
        queue.add(new QueueNode(root, 0));

        while (!queue.isEmpty()) {
            QueueNode current = queue.poll();
            Node tempNode = current.node;
            int hd = current.hd;

            // If this horizontal distance is not already present in the map, add it
            if (!topViewMap.containsKey(hd)) {
                topViewMap.put(hd, tempNode.data);
            }

            // Add the left and right children of the current node to the queue
            if (tempNode.left != null) {
                queue.add(new QueueNode(tempNode.left, hd - 1));
            }
            if (tempNode.right != null) {
                queue.add(new QueueNode(tempNode.right, hd + 1));
            }
        }

        // Extracting the values from the TreeMap to get the top view
        for (Map.Entry<Integer, Integer> entry : topViewMap.entrySet()) {
            result.add(entry.getValue());
        }

        return result;
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        List<Integer> topViewResult = topView(root);
        System.out.println("Top view of the binary tree is: " + topViewResult);
    }
}
