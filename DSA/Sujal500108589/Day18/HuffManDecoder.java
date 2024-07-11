// Definition for a Huffman tree node.
class TreeNode {
    char character;
    int frequency;
    TreeNode left;
    TreeNode right;

    TreeNode(char character, int frequency) {
        this.character = character;
        this.frequency = frequency;
        left = null;
        right = null;
    }
    
    TreeNode(int frequency) {
        this.character = '\0'; // null character for non-leaf nodes
        this.frequency = frequency;
        left = null;
        right = null;
    }
}

public class HuffManDecoder {
    public static String decode(TreeNode root, String binaryString) {
        StringBuilder decodedText = new StringBuilder();
        TreeNode current = root;

        for (int i = 0; i < binaryString.length(); i++) {
            char bit = binaryString.charAt(i);

            if (bit == '0') {
                current = current.left;
            } else {
                current = current.right;
            }

            // If we reach a leaf node, append the character to the result
            if (current.left == null && current.right == null) {
                decodedText.append(current.character);
                current = root; // Go back to the root for the next character
            }
        }

        return decodedText.toString();
    }

    public static void main(String[] args) {
        // Example usage
        
        // Create the Huffman tree for {(A: 3), (B: 1), (C: 1)}
        TreeNode root = new TreeNode(5); // root frequency is the sum of all frequencies
        
        root.left = new TreeNode('A', 3); // 'A' with frequency 3
        TreeNode right = new TreeNode(2); // internal node with frequency 2
        root.right = right;
        
        right.left = new TreeNode('B', 1); // 'B' with frequency 1
        right.right = new TreeNode('C', 1); // 'C' with frequency 1

        String binaryString = "1001011";
        String decodedText = decode(root, binaryString);
        
        System.out.println(decodedText); // Output: "ABCA"
    }
}
