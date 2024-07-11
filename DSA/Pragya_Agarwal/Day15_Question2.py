class Node:

    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def levelOrder(root):
    h = height(root)
    for i in range(1, h+1):
        current_level(root, i)

def current_level(root, level):
    if root is None:
        return
    if level == 1:
        print(root.data, end=" ")
    elif level > 1:
        current_level(root.left, level-1)
        current_level(root.right, level-1)

def height(node):
    if node is None:
        return 0
    else:

        left_height = height(node.left)
        right_height = height(node.right)

        if left_height > right_height:
            return left_height+1
        else:
            return right_height+1


if __name__ == '__main__':
    root = Node(3)
    root.left = Node(9)
    root.right = Node(20)
    root.right.left = Node(15)
    root.right.right = Node(7)

    print("Level order traversal of binary tree is:")
    levelOrder(root)
