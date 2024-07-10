import java.util.*;

class HuffmanNode {
    char data;
    HuffmanNode left, right;

    public HuffmanNode() {
        left = right = null;
    }
}

public class HuffmanDecoder {
    public static String decode(HuffmanNode root, String binaryString) {
        StringBuilder decodedText = new StringBuilder();
        HuffmanNode current = root;

        for (char bit : binaryString.toCharArray()) {
            if (bit == '0') {
                current = current.left;
            } else {
                current = current.right;
            }

            if (current.left == null && current.right == null) {
                decodedText.append(current.data);
                current = root;
            }
        }

        return decodedText.toString();
    }

    public static void main(String[] args) {
        HuffmanNode root = new HuffmanNode();
        root.left = new HuffmanNode();
        root.right = new HuffmanNode();
        root.left.data = 'B';
        root.right.left = new HuffmanNode();
        root.right.right = new HuffmanNode();
        root.right.left.data = 'C';
        root.right.right.data = 'A';

        String binaryString = "1001011";
        String decodedText = decode(root, binaryString);
        System.out.println("Decoded text: " + decodedText);
    }
}
