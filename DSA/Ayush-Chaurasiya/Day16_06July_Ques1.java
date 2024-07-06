import java.util.ArrayList;
import java.util.List;

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
    public static void postorder(MyTree root,List<Integer> result){
        if(root == null) return;
        postorder(root.left,result);
        postorder(root.right,result);
        result.add(root.data);
    }
}

public class Day16_06July_Ques1 {
    public static void main(String[] args) {
        MyTree root = new MyTree(1);
        root.left = new MyTree(2);
        root.left.left = new MyTree(4);
        root.left.right = new MyTree(5);

        root.right = new MyTree(3);

        List<Integer> result = new ArrayList<>();
        MyTree.postorder(root, result);
        System.out.println(result);
    }    
}
