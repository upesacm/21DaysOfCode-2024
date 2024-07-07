class Node {
    int value;
    Node left;
    Node right;

    Node(int value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree {
    Node root;

    Node findLCA(Node node, int n1, int n2) {
        if (node == null) {
            return null;
        }

        if (node.value > n1 && node.value > n2) {
            return findLCA(node.left, n1, n2);
        }

        if (node.value < n1 && node.value < n2) {
            return findLCA(node.right, n1, n2);
        }

        return node;
    }
}

public class Main {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(20);
        tree.root.left = new Node(10);
        tree.root.right = new Node(30);
        tree.root.left.left = new Node(5);
        tree.root.left.right = new Node(15);
        tree.root.right.left = new Node(25);
        tree.root.right.right = new Node(35);

        int node1 = 5;
        int node2 = 30;
        Node lca = tree.findLCA(tree.root, node1, node2);
        if (lca != null) {
            System.out.println("LCA of " + node1 + " and " + node2 + " is " + lca.value);
        } else {
            System.out.println("LCA not found");
        }
    }
}
