class TreeNode {
    char ch;
    int freq;
    TreeNode left, right;

    TreeNode(char ch, int freq) {
        this.ch = ch;
        this.freq = freq;
        left = right = null;
    }
}

public class HuffmanDecoding {
    public String decodeHuffman(TreeNode root, String binaryString) {
        StringBuilder decodedText = new StringBuilder();
        TreeNode currentNode = root;

        for (int i = 0; i < binaryString.length(); i++) {
            char bit = binaryString.charAt(i);

            if (bit == '0') {
                currentNode = currentNode.left;
            } else {
                currentNode = currentNode.right;
            }

            if (currentNode.left == null && currentNode.right == null) {
                decodedText.append(currentNode.ch);
                currentNode = root;
            }
        }

        return decodedText.toString();
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode('\0', 0);
        root.left = new TreeNode('A', 3);
        root.right = new TreeNode('\0', 0);
        root.right.left = new TreeNode('B', 1);
        root.right.right = new TreeNode('C', 1);

        HuffmanDecoding huffmanDecoding = new HuffmanDecoding();
        String binaryString = "1001011";
        String decodedText = huffmanDecoding.decodeHuffman(root, binaryString);

        System.out.println(decodedText);  // Output: "ABCA"
    }
}
