class TreeNode:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def height_of_binary_tree(root):
    if root is None:
        return -1  # Return -1 to indicate the height of an empty tree
    
    # Recursively calculate the height of the left and right subtrees
    left_height = height_of_binary_tree(root.left)
    right_height = height_of_binary_tree(root.right)
    
    # The height of the tree is the maximum height of the two subtrees plus one
    return max(left_height, right_height) + 1

if __name__ == "__main__":
    root = TreeNode(3)
    root.left = TreeNode(2)
    root.right = TreeNode(5)
    root.left.left = TreeNode(1)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(6)
    
    print(f"The height of the tree is: {height_of_binary_tree(root)}")

