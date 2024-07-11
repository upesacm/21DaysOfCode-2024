import java.util.*;
class Node 
{
    int data;
    Node left, right;
    Node(int item) 
    {
        data = item;
        left = right = null;
    }
}
class DAY18_S1
{
    Node root;

    public List<Integer> topView(Node root) 
    {
        class QueueItem {
            Node node;
            int horizontalDistance;
            QueueItem(Node n, int h) {
                node = n;
                horizontalDistance = h;
            }
        }

        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Map<Integer, Node> topViewMap = new TreeMap<>();
        Queue<QueueItem> queue = new LinkedList<>();

        queue.add(new QueueItem(root, 0));

        while (!queue.isEmpty()) {
            QueueItem current = queue.poll();
            Node currentNode = current.node;
            int hd = current.horizontalDistance;

            if (!topViewMap.containsKey(hd)) 
            {
                topViewMap.put(hd, currentNode);
            }

            if (currentNode.left != null) 
            {
                queue.add(new QueueItem(currentNode.left, hd - 1));
            }
            if (currentNode.right != null) 
            {
                queue.add(new QueueItem(currentNode.right, hd + 1));
            }
        }

        for (Node node : topViewMap.values()) 
        {
            result.add(node.data);
        }

        return result;
    }
    public static void main(String[] args) 
    {
        DAY18_S1 tree = new DAY18_S1();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
        tree.root.right.left = new Node(6);
        tree.root.right.right = new Node(7);

        System.out.println(tree.root);
    }
}
