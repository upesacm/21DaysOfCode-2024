class Node:
    def __init__(self, freq, char=None):
        self.freq = freq
        self.char = char
        self.left = None
        self.right = None

def decode_huffman(root, s):
    decoded_text = ""
    current = root
    for bit in s:
        if bit == '0':
            current = current.left
        else:
            current = current.right
        if current.char:
            decoded_text += current.char
            current = root
    return decoded_text

root = Node(None)
root.left = Node(None)
root.right = Node(3, 'A')
root.left.left = Node(1, 'B')
root.left.right = Node(1, 'C')

huffman_tree = root
binary_string = "1001011"

decoded_text = decode_huffman(huffman_tree, binary_string)
print(decoded_text)  
