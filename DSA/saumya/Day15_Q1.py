class Node:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None

def height(root):
  if root is None:
    return -1  # Base case: empty tree has height -1

  # Recursively calculate heights of left and right subtrees
  left_height = height(root.left)
  right_height = height(root.right)

  # Return the maximum height, adding 1 for the current level
  return 1 + max(left_height, right_height)

# test case
tree = Node(3)
tree.left = Node(2)
tree.left.left = Node(1)
tree.right = Node(5)
tree.right.left = Node(4)
tree.right.right = Node(6)

tree_height = height(tree)
print("Height of the tree:", tree_height) #output : 2
