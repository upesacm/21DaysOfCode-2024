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
  
class DAY16_S2
  {
  
    public List<Integer> inorderTraversal(TreeNode root) 
    {
      List<Integer> result = new ArrayList<>();
      traverseInorder(root, result);
      return result;
    }
  
    private void traverseInorder(TreeNode node, List<Integer> result) 
    {
      if (node == null) 
      {
        return;
      }
      traverseInorder(node.left, result); 
      result.add(node.val);
      traverseInorder(node.right, result); 
    }
  }