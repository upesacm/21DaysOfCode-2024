class Node:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		
def Height(root):
	if root is None:
		return -1
	else:
		left_height = Height(root.left)
		right_height = Height(root.right)

		return max(left_height,right_height)+1

root = Node(3)
root.left = Node(2)
root.right = Node(5)
root.left.left = Node(1)
root.right.left = Node(4)
root.right.right = Node(6)

print("Height of tree is: ",(Height(root)))
