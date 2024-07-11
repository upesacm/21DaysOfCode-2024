Day17-Question2-
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def insertIntoBST(root, val):
    if root is None:
        return TreeNode(val)
      
    current = root
    while True:
        if val < current.val:
            if current.left is None:
                current.left = TreeNode(val)
                break
            else:
                current = current.left
        else: 
            if current.right is None:
                current.right = TreeNode(val)
                break
            else:
                current = current.right

    return root

root = TreeNode(4)
root.left = TreeNode(2)
root.right = TreeNode(7)
root.left.left = TreeNode(1)
root.left.right = TreeNode(3)

new_root = insertIntoBST(root, 5)

def inorder_traversal(node):
    if node:
        inorder_traversal(node.left)
        print(node.val, end=' ')
        inorder_traversal(node.right)

inorder_traversal(new_root)
