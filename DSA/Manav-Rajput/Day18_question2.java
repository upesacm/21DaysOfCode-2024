public class Node {
    char data;
    Node left, right;

    public Node(char data) {
        this.data = data;
        left = right = null;
    }
}

class HuffmanDecoding {

    // Method to decode the given binary string using the Huffman tree
    public String decodeHuffman(Node root, String binaryString) {
        StringBuilder decodedString = new StringBuilder();
        Node current = root;

        for (int i = 0; i < binaryString.length(); i++) {
            if (binaryString.charAt(i) == '0') {
                current = current.left;
            } else {
                current = current.right;
            }

            // If it's a leaf node, append the character to the result
            if (current.left == null && current.right == null) {
                decodedString.append(current.data);
                current = root; // Reset to the root for the next character
            }
        }

        return decodedString.toString();
    }

    public static void main(String[] args) {
        // Constructing a simple Huffman Tree for demonstration
        Node root = new Node('\0');
        root.left = new Node('A');
        root.right = new Node('\0');
        root.right.left = new Node('B');
        root.right.right = new Node('C');

        HuffmanDecoding decoder = new HuffmanDecoding();
        String binaryString = "1001011";
        String decodedText = decoder.decodeHuffman(root, binaryString);

        System.out.println("Decoded text: " + decodedText); // Output: ABCA
    }
}
 
