class Node:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None

def newNode(data):
  return Node(data)

def find_LCA(node, n1, n2):
  if not node:
    return None
  if node.data > n1.data and node.data > n2.data:
    return findLCA(node.left, n1, n2)
  elif node.data < n1.data and node.data < n2.data:
    return findLCA(node.right, n1, n2)
  else:
    return node

root = newNode(24)
root.left = newNode(8)
root.right = newNode(20)
root.left.left = newNode(14)
root.left.right = newNode(12)
root.left.right.left = newNode(6)
root.left.right.right = newNode(10)

n1 = root.left.right.left 
n2 = root.right            

lca = find_LCA(root, n1, n2)

if lca:
  print("LCA of", n1.data, "and", n2.data, "is", lca.data) # output : 8
else:
  print("LCA not found")
