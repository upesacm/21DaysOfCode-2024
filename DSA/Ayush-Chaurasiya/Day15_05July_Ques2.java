import java.util.ArrayList;
import java.util.List;

class MyTree{
    int data;
    MyTree left;
    MyTree right;

    MyTree(int data){
        this.data = data;
    }

    public static void traverseBFS(MyTree root,List<Integer> result ){
        if(root == null){
            return;
        }
        else{
            result.add(root.data);
            traverseBFS(root.left, result);
            traverseBFS(root.right, result);
        }
    }
}


public class Day15_05July_Ques2 {
    public static void main(String[] args) {
        MyTree root = new MyTree(3);
        root.left = new MyTree(9);
        root.right = new MyTree(20);
        root.right.left = new MyTree(15);
        root.right.right = new MyTree(7);

        List<Integer> result = new ArrayList<Integer>();
        MyTree.traverseBFS(root,result);
        System.out.println(result);
    }
}
