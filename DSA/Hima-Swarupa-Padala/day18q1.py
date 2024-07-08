class TreeNode:  
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def top_view(root):
    if not root:
        return []

    hd_dict = {}
    node_dict = {}

    def traverse(node, hd, level):       
        if not node:
            return            
        if hd not in hd_dict or level < hd_dict[hd]:
            hd_dict[hd] = level
            node_dict[hd] = node.value
        traverse(node.left, hd - 1, level + 1)
        traverse(node.right, hd + 1, level + 1)

    traverse(root, 0, 0)

    sorted_nodes = [node_dict[hd] for hd in sorted(hd_dict.keys())]

    return sorted_nodes

if __name__ == "__main__":

    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    top_view_nodes = top_view(root)    
    print(top_view_nodes)
