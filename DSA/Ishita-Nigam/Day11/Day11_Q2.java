import java.util.PriorityQueue;
import java.util.Scanner;

public class Day11_Q2 {
    private PriorityQueue<Integer> minHeap;

    public Day11_Q2() {
        minHeap = new PriorityQueue<>();
    }

    // Insert an item into the priority queue
    public void insert(int data) {
        minHeap.add(data);
    }

    // Extract the minimum item from the priority queue
    public int extractMin() {
        if (minHeap.isEmpty()) {
            System.out.println("Priority queue is empty");
            return -1;
        }
        return minHeap.poll();
    }

    public static void main(String[] args) {
        Day11_Q2 pq = new Day11_Q2();
        Scanner scanner = new Scanner(System.in);
        String command;

        System.out.println("Enter commands: insert <number>, extract_min, or exit to quit.");

        while (true) {
            command = scanner.nextLine();
            if (command.equalsIgnoreCase("exit")) {
                break;
            } else if (command.startsWith("insert")) {
                String[] parts = command.split(" ");
                if (parts.length == 2) {
                    try {
                        int value = Integer.parseInt(parts[1]);
                        pq.insert(value);
                        System.out.println("Inserted: " + value);
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid number: " + parts[1]);
                    }
                } else {
                    System.out.println("Invalid command. Use: insert <number>");
                }
            } else if (command.equalsIgnoreCase("extract_min")) {
                int min = pq.extractMin();
                if (min != -1) {
                    System.out.println("Extracted Min: " + min);
                }
            } else {
                System.out.println("Invalid command. Use: insert <number>, extract_min, or exit.");
            }
        }

        scanner.close();
    }
}
