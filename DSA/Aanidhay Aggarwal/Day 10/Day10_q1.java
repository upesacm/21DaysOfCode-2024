import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static Deque<Integer> reverseDeque(Deque<Integer> dq) {
        Deque<Integer> reversedDq = new LinkedList<>();
        while(!dq.isEmpty()) {
            reversedDq.push(dq.pop());
        }
        return reversedDq;
    }

    public static void main(String[] args) {
        Deque<Integer> dq = new LinkedList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        System.out.print("Enter the elements: ");
        for(int i = 0; i < n; i++) {
            dq.add(scanner.nextInt());
        }
        System.out.print("Queue: ");
        for(int elem : dq) {
            System.out.print(elem + " ");
        }
        System.out.println();
        Deque<Integer> reversedDq = reverseDeque(new LinkedList<>(dq));
        System.out.print("Reversed deque: ");
        for(int elem : reversedDq) {
            System.out.print(elem + " ");
        }
        System.out.println();
    }
}
