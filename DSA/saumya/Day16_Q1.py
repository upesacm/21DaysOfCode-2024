class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def postorder_traversal(root):
  if not root:
    return []

  result = []
  postorder_helper(root, result)
  return result

def postorder_helper(node, result):
  if not node:
    return

  # Traverse left subtree
  postorder_helper(node.left, result)

  # Traverse right subtree
  postorder_helper(node.right, result)

  # Visit root node
  result.append(node.val)

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

postorder = postorder_traversal(root)
print(postorder)  # Output: [4, 5, 2, 3, 1]
