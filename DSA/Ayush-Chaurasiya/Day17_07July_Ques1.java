class MyTree {
    int data;
    MyTree left, right;

    MyTree(int data) {
        this.data = data;
        this.left = this.right = null;
    }

    public static MyTree findLCA(MyTree root, MyTree node1, MyTree node2) {
        if (root == null) return null;
        if (node1.data < root.data && node2.data < root.data) {
            return findLCA(root.left, node1, node2);
        }
      
        if (node1.data > root.data && node2.data > root.data) {
            return findLCA(root.right, node1, node2);
        }
      
        return root;
    }
}

public class Day17_07July_Ques1 {
    public static void main(String[] args) {
        MyTree root = new MyTree(20);
        root.left = new MyTree(10);
        root.right = new MyTree(30);
        root.left.left = new MyTree(5);
        root.left.right = new MyTree(15);
        root.right.left = new MyTree(25);
        root.right.right = new MyTree(35);

        MyTree node1 = root.left.left;  // Node with value 5
        MyTree node2 = root.right;      // Node with value 30

        MyTree lca = MyTree.findLCA(root, node1, node2);

        if (lca != null) {
            System.out.println("The LCA of node " + node1.data + " and node " + node2.data + " is: " + lca.data);
        } else {
            System.out.println("No common ancestor found.");
        }
    }
}
