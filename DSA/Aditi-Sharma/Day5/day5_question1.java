import java.util.LinkedList;

public class LinkedListTraversal {
    public static void main(String[] args) {
        LinkedList<Integer> linkedList = new LinkedList<>();
        linkedList.add(1);
        linkedList.add(2);
        linkedList.add(3);
        linkedList.add(4);
        LinkedListTraversal(linkedList);
}
      public static void LinkedListTraversal( LinkedList<Integer> linkedList){ 
        System.out.print("Iterating the LinkedList using a simple for loop: ");
        for (int i = linkedList.size()-1; i >=0; i--) {
            System.out.print(linkedList.get(i) + " ");
        }
    }
}
