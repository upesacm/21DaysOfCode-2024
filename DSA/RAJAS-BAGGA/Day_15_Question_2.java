import java.util.Queue;
import java.util.LinkedList;
import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Day_15_Question_2 {
    public static List<Integer> levelOrderTraversal(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);

        List<Integer> list = new ArrayList<Integer>();

        while (!queue.isEmpty()) {
            TreeNode temp = queue.poll();
            list.add(temp.val);

            if (temp.left != null)
                queue.add(temp.left);

            if (temp.right != null)
                queue.add(temp.right);
        }
        return list;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        TreeNode n1 = new TreeNode(9);
        TreeNode n2 = new TreeNode(20);
        TreeNode n3 = new TreeNode(15);
        TreeNode n4 = new TreeNode(7);


        root.left = n1;
        root.right = n2;
        n2.left = n3;
        n2.right = n4;

        System.out.println(levelOrderTraversal(root));
    }
}
