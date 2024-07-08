    #       1
    #      / \
    #     2   3
    #    / \
    #   4   5

class TreeNode:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def inorder_traversal(root):
    if root is None:
        return []
    return inorder_traversal(root.left) + [root.value] + inorder_traversal(root.right)

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    print(f"Inorder traversal: {inorder_traversal(root)}")

if __name__ == "__main__":
     main()
    
