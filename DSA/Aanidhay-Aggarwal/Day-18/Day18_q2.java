import java.util.*;

class TreeNode {
    char val;
    int frequency;
    TreeNode left;
    TreeNode right;
    TreeNode(char x) { val = x; frequency = 0; }
}

public class Main {
    public static String decode(TreeNode root, String binaryString) {
        if (root == null) {
            return "";
        }

        StringBuilder result = new StringBuilder();
        TreeNode current = root;

        for (char c : binaryString.toCharArray()) {
            if (c == '0') {
                current = current.left;
            } else {
                current = current.right;
            }

            if (current.left == null && current.right == null) {
                result.append(current.val);
                current = root;
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of nodes in the Huffman tree:");
        int n = scanner.nextInt();

        System.out.println("Enter the characters and their frequencies:");
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char c = scanner.next().charAt(0);
            int frequency = scanner.nextInt();
            frequencyMap.put(c, frequency);
        }

        System.out.println("Enter the binary string:");
        String binaryString = scanner.next();

        TreeNode root = createHuffmanTree(frequencyMap);

        String result = decode(root, binaryString);
        System.out.println("Decoded text: " + result);
    }

    public static TreeNode createHuffmanTree(Map<Character, Integer> frequencyMap) {
        PriorityQueue<TreeNode> queue = new PriorityQueue<>((a, b) -> a.frequency - b.frequency);

        for (Map.Entry<Character, Integer> entry : frequencyMap.entrySet()) {
            TreeNode node = new TreeNode(entry.getKey());
            node.frequency = entry.getValue();
            queue.add(node);
        }

        while (queue.size() > 1) {
            TreeNode left = queue.poll();
            TreeNode right = queue.poll();
            TreeNode internalNode = new TreeNode(' ');
            internalNode.left = left;
            internalNode.right = right;
            internalNode.frequency = left.frequency + right.frequency;
            queue.add(internalNode);
        }

        return queue.poll();
    }
}
