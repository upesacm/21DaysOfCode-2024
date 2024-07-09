import java.util.*;
class HuffmanNode {
    char data;
    HuffmanNode left;
    HuffmanNode right;

    public HuffmanNode(char data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class Day18_Q2 {

    public static String decodeHuffmanTree(HuffmanNode root, String binaryString) {
        StringBuilder decodedString = new StringBuilder();
        HuffmanNode current = root;

        for (char bit : binaryString.toCharArray()) {
            if (bit == '0') {
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

    public static HuffmanNode buildSampleHuffmanTree() {
        HuffmanNode root = new HuffmanNode('\0');
        root.right = new HuffmanNode('A');
        root.left = new HuffmanNode('\0');
        root.left.left = new HuffmanNode('B');
        root.left.right = new HuffmanNode('C');
        return root;
    }

    public static void main(String[] args) {
        HuffmanNode root = buildSampleHuffmanTree();
        String binaryString = "1001011";
        String decodedText = decodeHuffmanTree(root, binaryString);
        System.out.println("Decoded Text: " + decodedText);
    }
}
