// Question - 1
// Author - Ayush Dey

import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class Q1{
    Node root;

    void topView(Node node, int hd, Map<Integer, Integer> map) {
        if (node == null) {
            return;
        }

        if (!map.containsKey(hd)) {
            map.put(hd, node.data);
        }

        topView(node.left, hd - 1, map);
        topView(node.right, hd + 1, map);
    }

    List<Integer> topView(Node node) {
        Map<Integer, Integer> map = new TreeMap<>();
        topView(node, 0, map);
        return new ArrayList<>(map.values());
    }

    public static void main(String args[]) {
        Q1 tree = new Q1();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.right = new Node(4);
        tree.root.left.right.right = new Node(5);
        tree.root.left.right.right.right = new Node(6);
        tree.root.right.left = new Node(7);

        List<Integer> result = tree.topView(tree.root);
        System.out.println("Top view of the given binary tree is: " + result);
    }
}