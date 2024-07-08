class MyTree{
    int data;
    MyTree left;
    MyTree right;

    MyTree(int data){
        this.data = data;
    }
    public static int height(MyTree root){
        if(root == null) return -1;
        return 1+ Math.max(height(root.left), height(root.right));
    }

}

public class Day15_05July_Ques1 {
    public static void main(String[] args) {
        MyTree root = new MyTree(3);
        root.left = new MyTree(2);
        root.left.left = new MyTree(1);

        root.right = new MyTree(5);
        root.right.left = new MyTree(4);
        root.right.right = new MyTree(6);

        System.out.println(MyTree.height(root));
    }
}
