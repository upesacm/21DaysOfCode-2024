import java.util.*;

class HuffmanNode {
    char data;
    int frequency;
    HuffmanNode left, right;

    HuffmanNode(char data, int frequency) {
        this.data = data;
        this.frequency = frequency;
        this.left = this.right = null;
    }
}

class Day18_08July_Ques2 {
    public static String decodeHuffman(HuffmanNode root, String binaryString) {
        StringBuilder decodedText = new StringBuilder();
        HuffmanNode current = root;
        
        for (char bit : binaryString.toCharArray()) {
            if (bit == '0') {
                current = current.left;
            } else {
                current = current.right;
            }
            
            // If leaf node is reached
            if (current.left == null && current.right == null) {
                decodedText.append(current.data);
                current = root; // Go back to the root for next character
            }
        }
        
        return decodedText.toString();
    }

    public static void main(String[] args) {
        // Example Huffman Tree for characters A, B, and C
        HuffmanNode root = new HuffmanNode('-', 0);
        root.left = new HuffmanNode('A', 3);
        root.right = new HuffmanNode('-', 0);
        root.right.left = new HuffmanNode('B', 1);
        root.right.right = new HuffmanNode('C', 1);

        String binaryString = "1001011";
        String decodedText = decodeHuffman(root, binaryString);
        System.out.println("Decoded Text: " + decodedText);
    }
}
