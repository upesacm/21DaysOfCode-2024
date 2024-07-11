class TreeNode {
    char data;
    TreeNode left, right;

    public TreeNode(char data) {
        this.data = data;
        left = right = null;
    }
}

public class HuffmanDecoder {
    public static String decodeHuffman(TreeNode root, String binaryString) {
        StringBuilder decodedText = new StringBuilder();
        TreeNode current = root;

        for (int i = 0; i < binaryString.length(); i++) {
            if (binaryString.charAt(i) == '0') {
                current = current.left;
            } else {
                current = current.right;
            }

            // If current is a leaf node
            if (current.left == null && current.right == null) {
                decodedText.append(current.data);
                current = root; // Go back to the root for the next character
            }
        }

        return decodedText.toString();
    }

    public static void main(String[] args) {
        // Construct the Huffman tree
        // Huffman Tree: {(A: 3), (B: 1), (C: 1)}
        TreeNode root = new TreeNode('\0');
        root.left = new TreeNode('A');
        root.right = new TreeNode('\0');
        root.right.left = new TreeNode('B');
        root.right.right = new TreeNode('C');

        String binaryString = "1001011";
        String decodedText = decodeHuffman(root, binaryString);

        System.out.println(decodedText); // Output: "ABCA"
    }
}
