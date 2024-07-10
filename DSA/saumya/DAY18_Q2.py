class HuffmanNode:
    def __init__(self, character, frequency):
        self.character = character
        self.frequency = frequency
        self.left = None
        self.right = None

class decode_text:
    def __init__(self, root):
        self.root = root

    def decode(self, binary_string):
        decoded_text = []
        current_node = self.root
        for bit in binary_string:
            if bit == '0':
                current_node = current_node.left
            else:
                current_node = current_node.right
            if current_node.left is None and current_node.right is None:
                decoded_text.append(current_node.character)
                current_node = self.root
        return ''.join(decoded_text)

node_a = HuffmanNode('A', 3)
node_b = HuffmanNode('B', 1)
node_c = HuffmanNode('C', 1)
internal_node = HuffmanNode('*', 2)
internal_node.left = node_b
internal_node.right = node_c

root = HuffmanNode('*', 5)
root.left = node_a
root.right = internal_node
huffman_tree = decode_text(root)
binary_string = "1001011"
decoded_text = huffman_tree.decode(binary_string)
print("Decoded text:", decoded_text)

