class MyTree {
    int data;
    MyTree left, right;

    MyTree(int data) {
        this.data = data;
        this.left = this.right = null;
    }

    public static MyTree insert(MyTree root, int value) {
        if (root == null) {
            return new MyTree(value);
        }

        if (value < root.data) {
            root.left = insert(root.left, value);
        } else if (value > root.data) {
            root.right = insert(root.right, value);
        }

        return root;
    }
    public static void inOrderTraversal(MyTree root) {
        if (root != null) {
            inOrderTraversal(root.left);
            System.out.print(root.data + " ");
            inOrderTraversal(root.right);
        }
    }
}

public class Day17_07July_Ques2 {
    public static void main(String[] args) {
        MyTree root = new MyTree(4);
        root.left = new MyTree(2);
        root.right = new MyTree(7);
        root.left.left = new MyTree(1);
        root.left.right = new MyTree(3);

        System.out.println("Original BST (in-order): ");
        MyTree.inOrderTraversal(root);
        System.out.println();

        int valueToInsert = 5;
        root = MyTree.insert(root, valueToInsert);

        System.out.println("Updated BST after inserting " + valueToInsert + " (in-order): ");
        MyTree.inOrderTraversal(root);
        System.out.println();
    }
}
