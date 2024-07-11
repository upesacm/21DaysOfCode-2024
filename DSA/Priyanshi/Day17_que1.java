class Node {
    int data;
    Node left, right;

    Node(int v) {
        data = v;
        left = right = null;
    }
}

class Day17_que1 {

    public static Node findLCA(Node root, int n1, int n2) {
        if (root == null) {
            return null;
        }

        // If both n1 and n2 are smaller than root, then LCA lies in left subtree
        if (root.data > n1 && root.data > n2) {
            return findLCA(root.left, n1, n2);
        }

        // If both n1 and n2 are greater than root, then LCA lies in right subtree
        if (root.data < n1 && root.data < n2) {
            return findLCA(root.right, n1, n2);
        }

        // If one of n1 or n2 is smaller and the other is larger, root is the LCA
        return root;
    }

    public static void main(String[] args) {
        Node root = new Node(20);
        root.left = new Node(10);
        root.right = new Node(30);
        root.left.left = new Node(5);
        root.left.right = new Node(15);
        root.right.left = new Node(25);
        root.right.right = new Node(35);

        int n1 = 5, n2 = 30;
        Node lca = findLCA(root, n1, n2);

        System.out.println("Lowest Common Ancestor of " + n1 + " and " + n2 + " is: " + lca.data);
    }
}
