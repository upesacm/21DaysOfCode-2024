import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class MyTree {
    int data;
    MyTree left;
    MyTree right;

    MyTree(int data) {
        this.data = data;
    }

    public static List<Integer> traverseBFS(MyTree root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Queue<MyTree> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            MyTree currentNode = queue.poll();
            result.add(currentNode.data);

            if (currentNode.left != null) {
                queue.add(currentNode.left);
            }

            if (currentNode.right != null) {
                queue.add(currentNode.right);
            }
        }

        return result;
    }
}

public class Day15_05July_Ques2 {
    public static void main(String[] args) {
        MyTree root = new MyTree(3);
        root.left = new MyTree(9);
        root.left.left = new MyTree(7);
        root.left.right = new MyTree(8);
        
        root.right = new MyTree(20);
        root.right.left = new MyTree(15);
        root.right.right = new MyTree(7);

        List<Integer> result = MyTree.traverseBFS(root);
        System.out.println(result);
    }
}
