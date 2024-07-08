import java.util.ArrayList;
import java.util.List;
class TreeNode 
{
    int val;
    TreeNode left;
    TreeNode right;
  
    TreeNode(int val) 
    {
      this.val = val;
    }
  }
  class DAY16_S1
  {
  
    public List<Integer> postorderTraversal(TreeNode root) 
    {
      List<Integer> result = new ArrayList<>();
      traversePostorder(root, result);
      return result;
    }
  
    private void traversePostorder(TreeNode node, List<Integer> result) 
    {
      if (node == null) 
      {
        return;
      }
      traversePostorder(node.left, result);
      traversePostorder(node.right, result);
      result.add(node.val);
    }
  }