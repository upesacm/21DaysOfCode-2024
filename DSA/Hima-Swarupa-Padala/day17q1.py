class TreeNode:   
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def find_LCA(root, node1, node2):
    if not root:
        return None

    if root.val > node1 and root.val > node2:
        return find_LCA(root.left, node1, node2)

    elif root.val < node1 and root.val < node2:
        return find_LCA(root.right, node1, node2)

    return root

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
