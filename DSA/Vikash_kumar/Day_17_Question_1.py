Day17-Question1-
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def lowestCommonAncestor(root, p, q):
    if root is None:
        return None
   
    if p.val < root.val and q.val < root.val:
        return lowestCommonAncestor(root.left, p, q)
   
    if p.val > root.val and q.val > root.val:
        return lowestCommonAncestor(root.right, p, q)
   
    return root
  
root = TreeNode(20)
root.left = TreeNode(10)
root.right = TreeNode(30)
root.left.left = TreeNode(5)
root.left.right = TreeNode(15)
root.right.left = TreeNode(25)
root.right.right = TreeNode(35)

p = TreeNode(5)
q = TreeNode(30)

lca_node = lowestCommonAncestor(root, p, q)
print("LCA:", lca_node.val)  
