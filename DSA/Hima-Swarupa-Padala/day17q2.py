class TreeNode:    
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert_into_BST(root, value):
    if not root:
        return TreeNode(value)  

    if value > root.val:
        root.right = insert_into_BST(root.right, value)  
    elif value < root.val:
        root.left = insert_into_BST(root.left, value) 

    return root

root = TreeNode(4)
root.left = TreeNode(2)
root.right = TreeNode(7)
root.left.left = TreeNode(1)
root.left.right = TreeNode(3)

new_value = 5
root = insert_into_BST(root, new_value)

def inorder_traversal(node):
    if not node:
        return
    inorder_traversal(node.left)
    print(node.val, end=" ")
    inorder_traversal(node.right)

inorder_traversal(root)
