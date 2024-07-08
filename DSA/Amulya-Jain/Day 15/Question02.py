class TreeNode:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def level_order_traversal(root):
    if root is None:
        return []
    
    result = []
    queue = [root]
    
    while queue:
        node = queue.pop(0)  # Dequeue the first element
        result.append(node.value)
        
        if node.left:
            queue.append(node.left)  # Enqueue the left child
        if node.right:
            queue.append(node.right)  # Enqueue the right child
    
    return result

if __name__ == "__main__":
    #       3
    #      / \
    #     9  20
    #       /  \
    #      15   7
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    
    print(f"Level order traversal of the tree: {level_order_traversal(root)}")
