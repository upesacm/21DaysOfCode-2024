class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None

def InOrder(node):
    if node == None:
        return 
    
    InOrder(node.left)
    print(node.data,end=" ")
    InOrder(node.right)

if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

print("Inorder Traversal:")
InOrder(root)
    
