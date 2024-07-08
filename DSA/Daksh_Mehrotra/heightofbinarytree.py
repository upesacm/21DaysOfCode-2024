class TreeNode:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right
def height_of_binary_tree(root):
    if root is None:
        return -1
    left_height = height_of_binary_tree(root.left)
    right_height = height_of_binary_tree(root.right)
    return max(left_height, right_height) + 1
if __name__ == "__main__":
    root = TreeNode(3)
    root.left = TreeNode(2)
    root.right = TreeNode(5)
    root.left.left = TreeNode(1)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(6)
    print(f"The height of the binary tree is: {height_of_binary_tree(root)}")
