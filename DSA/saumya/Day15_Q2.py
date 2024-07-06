class Node:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None

def level_order_traversal(root):
  if not root:
    return []

  traversal = []
  queue = [root]
  while queue:
    level_size = len(queue)
    for _ in range(level_size):
      current_node = queue.pop(0)
      traversal.append(current_node.data)
      if current_node.left:
        queue.append(current_node.left)
      if current_node.right:
        queue.append(current_node.right)
  return traversal

# test case
tree = Node(3)
tree.left = Node(9)
tree.right = Node(20)
tree.right.left = Node(15)
tree.right.right = Node(7)

level_order = level_order_traversal(tree)
print("Level order traversal:", level_order)
