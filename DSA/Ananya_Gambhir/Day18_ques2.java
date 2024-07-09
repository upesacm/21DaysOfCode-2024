import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class HuffmanNode {
    char character;
    HuffmanNode left;
    HuffmanNode right;

    
    HuffmanNode(char character) {
        this.character = character;
        this.left = null;
        this.right = null;
    }

    HuffmanNode(HuffmanNode left, HuffmanNode right) {
        this.character = '\0';  // Empty character for internal nodes
        this.left = left;
        this.right = right;
    }
}

public class HuffmanDecoder {
    public static String decode(HuffmanNode root, String binaryString) {
        StringBuilder decodedText = new StringBuilder();
        HuffmanNode currentNode = root;
        
        for (int i = 0; i < binaryString.length(); i++) {
            currentNode = binaryString.charAt(i) == '0' ? currentNode.left : currentNode.right;
            
      
            if (currentNode.left == null && currentNode.right == null) {
                decodedText.append(currentNode.character);
                currentNode = root; 
            }
        }
        
        return decodedText.toString();
    }

  
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        
        HuffmanNode root = new HuffmanNode(
                new HuffmanNode(
                        new HuffmanNode('A'),
                        new HuffmanNode('B')
                ),
                new HuffmanNode(
                        new HuffmanNode('C'),
                        new HuffmanNode('D')
                )
        );

        System.out.print("Enter the binary string to decode: ");
        String binaryString = scanner.nextLine();

     
        String decodedText = decode(root, binaryString);

     
        System.out.println("Decoded text: " + decodedText);

        scanner.close();
    }
}
