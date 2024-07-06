class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def postorder_traversal(root):
    result = []
    
    def traverse(node):
        if node:
            traverse(node.left)
            traverse(node.right)
            result.append(node.value)
    traverse(root)
    return result

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

result = postorder_traversal(root)
print(result)
