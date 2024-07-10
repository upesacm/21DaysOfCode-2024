class HuffmanNode {
    char data;
    int frequency;
    HuffmanNode left, right;
    HuffmanNode(char data, int frequency) {
        this.data = data;
        this.frequency = frequency;
        this.left = this.right = null;
    }

    HuffmanNode(int frequency) {
        this.data = '\0';
        this.frequency = frequency;
        this.left = this.right = null;
    }
}

class HuffmanTree {
    HuffmanNode root;
    public String decode(HuffmanNode root, String binaryString) {
        StringBuilder decodedString = new StringBuilder();
        HuffmanNode current = root;
        for (int i = 0; i < binaryString.length(); i++) {
            if (binaryString.charAt(i) == '0') {
                current = current.left;
            } else {
                current = current.right;
            }
            if (current.left == null && current.right == null) {
                decodedString.append(current.data);
                current = root;
            }
        }
        return decodedString.toString();
    }

    public static void main(String[] args) {
        HuffmanTree tree = new HuffmanTree();
        tree.root = new HuffmanNode(5);
        tree.root.left = new HuffmanNode(2);
        tree.root.right = new HuffmanNode('A', 3);
        tree.root.left.left = new HuffmanNode('B', 1);
        tree.root.left.right = new HuffmanNode('C', 1);
        String binaryString = "1001011";
        String decodedText = tree.decode(tree.root, binaryString);
        System.out.println("Decoded text: " + decodedText);
    }
}
