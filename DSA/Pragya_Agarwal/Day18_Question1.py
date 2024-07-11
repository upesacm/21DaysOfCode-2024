class newNode:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None
        self.val = 0
 
def topview(root):
    if(root == None):
        return
    q = []
    m = dict()
    val = 0
    root.val = val
    q.append(root)
 
    while(len(q)):
        root = q[0]
        val = root.val
 
        if val not in m:
            m[val] = root.data
        if(root.left):
            root.left.val = val - 1
            q.append(root.left)
 
        if(root.right):
            root.right.val = val + 1
            q.append(root.right)
 
        q.pop(0)
    for i in sorted(m):
        print(m[i], end=" ")
 
if __name__ == '__main__':
    root = newNode(1)
    root.left = newNode(2)
    root.right = newNode(3)
    root.left.left = newNode(4)
    root.left.right = newNode(5)
    root.right.left = newNode(6)
    root.right.right = newNode(7)
    print("The top view: ")
    topview(root)
