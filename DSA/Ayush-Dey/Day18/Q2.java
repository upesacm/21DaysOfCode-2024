// Question - 2
// Author - Ayush Dey

import java.util.*;

class Node {
    char data;
    Node left, right;

    Node(char item) {
        data = item;
        left = right = null;
    }
}

class Q2 {
    Node root;

    String decode(String binaryString) {
        Node current = root;
        StringBuilder result = new StringBuilder();

        for (char c : binaryString.toCharArray()) {
            if (c == '0') {
                current = current.left;
            } else {
                current = current.right;
            }

            if (current.left == null && current.right == null) {
                result.append(current.data);
                current = root;
            }
        }

        return result.toString();
    }

    public static void main(String args[]) {
        Q2 tree = new Q2();
        tree.root = new Node('\0');
        tree.root.left = new Node('B');
        tree.root.right = new Node('\0');
        tree.root.right.left = new Node('A');
        tree.root.right.right = new Node('C');

        String binaryString = "1001011";
        String result = tree.decode(binaryString);
        System.out.println("Decoded text is: " + result);
    }
}