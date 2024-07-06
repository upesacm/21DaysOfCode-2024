Day15-Question1-
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def height_of_binary_tree(root):
    if not root:
        return -1
    
    left_height = height_of_binary_tree(root.left)
    right_height = height_of_binary_tree(root.right)
    
    return 1 + max(left_height, right_height)

root = TreeNode(3)
root.left = TreeNode(2)
root.left.left = TreeNode(1)
root.right = TreeNode(5)
root.right.left = TreeNode(4)
root.right.right = TreeNode(6)

height = height_of_binary_tree(root)
print("Height of the binary tree:", height)  
