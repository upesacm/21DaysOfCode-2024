class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def tree_height(root):
    if root is None:
        return -1
    else:
        left_height = tree_height(root.left)
        right_height = tree_height(root.right)
        return max(left_height, right_height) + 1

root = TreeNode(3)
root.left = TreeNode(2)
root.right = TreeNode(5)
root.left.left = TreeNode(1)
root.left.right = TreeNode(4)
root.right.right = TreeNode(6)

print(tree_height(root))
  