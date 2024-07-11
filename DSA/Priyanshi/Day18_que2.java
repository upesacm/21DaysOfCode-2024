class Node {
    char data;
    int frequency;
    Node left, right;

    Node(char data, int frequency) {
        this.data = data;
        this.frequency = frequency;
        left = right = null;
    }

    Node(int frequency) {
        this.data = '\0';  // Use a special character to indicate non-leaf nodes
        this.frequency = frequency;
        left = right = null;
    }
}

class Day18_que2 {

    // Function to decode the binary string using the Huffman tree
    public static String decodeHuffman(Node root, String binaryString) {
        StringBuilder decodedText = new StringBuilder();
        Node currentNode = root;

        for (int i = 0; i < binaryString.length(); i++) {
            if (binaryString.charAt(i) == '0') {
                currentNode = currentNode.left;
            } else {
                currentNode = currentNode.right;
            }

            // If a leaf node is reached, append the character to the decoded text
            if (currentNode.left == null && currentNode.right == null) {
                decodedText.append(currentNode.data);
                currentNode = root; // Go back to the root for the next character
            }
        }

        return decodedText.toString();
    }

    public static void main(String[] args) {
        // Construct the Huffman tree for the example {(A: 3), (B: 1), (C: 1)}
        Node root = new Node(5);
        root.left = new Node('A', 3);
        root.right = new Node(2);
        root.right.left = new Node('B', 1);
        root.right.right = new Node('C', 1);

        String binaryString = "1001011";
        String decodedText = decodeHuffman(root, binaryString);

        System.out.println("Decoded text: " + decodedText); // Output: "ABCA"
    }
}
