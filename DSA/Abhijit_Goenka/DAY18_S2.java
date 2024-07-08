class HuffmanNode 
{
    char character;
    int frequency;
    HuffmanNode left;
    HuffmanNode right;

    HuffmanNode(char character, int frequency) 
    {

        this.character = character;
        this.frequency = frequency;
        this.left = null;
        this.right = null;
    }
}

class DAY18_S2
{
    HuffmanNode root;

    DAY18_S2(HuffmanNode root) 
    {
        this.root = root;
    }
    public String decode(String binaryString) 
    {
        StringBuilder decodedText = new StringBuilder();
        HuffmanNode currentNode = root;
        for (int i = 0; i < binaryString.length(); i++) 
        {
            char bit = binaryString.charAt(i);
            if (bit == '0') {
                currentNode = currentNode.left;
            } else if (bit == '1') {
                currentNode = currentNode.right;
            }
            if (currentNode.left == null && currentNode.right == null) 
            {
                decodedText.append(currentNode.character);
                currentNode = root;
            }
        }
        return decodedText.toString();
    }
    public static void main(String[] args) 
    {
        HuffmanNode nodeA = new HuffmanNode('A', 3);
        HuffmanNode nodeB = new HuffmanNode('B', 1);
        HuffmanNode nodeC = new HuffmanNode('C', 1);
        HuffmanNode internalNode = new HuffmanNode('*', 2);
        internalNode.left = nodeB;
        internalNode.right = nodeC;

        HuffmanNode root = new HuffmanNode('*', 5);
        root.left = nodeA;
        root.right = internalNode;
        DAY18_S2 huffmanTree = new DAY18_S2(root);
        String binaryString = "1001011";
        String decodedText = huffmanTree.decode(binaryString);
        System.out.println("Decoded text: " + decodedText); 
    }
}
