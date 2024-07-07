class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def find_LCA(root, node1, node2):
    if not root:
        return None

    # If both n1 and n2 are smaller than root, LCA lies in the left subtree
    if root.val > node1 and root.val > node2:
        return find_LCA(root.left, node1, node2)

    # If both n1 and n2 are greater than root, LCA lies in the right subtree
    elif root.val < node1 and root.val < node2:
        return find_LCA(root.right, node1, node2)

    # Otherwise, root is the LCA (assuming both n1 and n2 are present in the BST)
    return root

# Example usage
root = TreeNode(20)
root.left = TreeNode(10)
root.right = TreeNode(30)
root.left.left = TreeNode(5)
root.left.right = TreeNode(15)
root.right.left = TreeNode(25)
root.right.right = TreeNode(35)

node1, node2 = 5, 30
lca_node = find_LCA(root, node1, node2)
print(lca_node.val)
