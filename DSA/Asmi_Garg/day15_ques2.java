import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
        left = right = null;
    }
}

public class BinaryTree2 {

    public List<Integer> levelOrderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode currentNode = queue.poll();
            result.add(currentNode.val);

            if (currentNode.left != null) {
                queue.add(currentNode.left);
            }

            if (currentNode.right != null) {
                queue.add(currentNode.right);
            }
        }

        return result;
    }

    public static void main(String[] args) {

        BinaryTree tree = new BinaryTree();
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        List<Integer> result = tree.levelOrderTraversal(root);
        System.out.println(result); 
    }
}
