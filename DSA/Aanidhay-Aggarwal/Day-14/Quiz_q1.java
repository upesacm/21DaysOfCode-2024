import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] height = new int[n];
        for (int i = 0; i < n; i++) {
            height[i] = scanner.nextInt();
        }

        int moves = 0;
        while (!isNonDecreasing(height)) {
            height = removeStudents(height);
            moves++;
        }

        System.out.println(moves);
    }

    private static boolean isNonDecreasing(int[] height) {
        for (int i = 1; i < height.length; i++) {
            if (height[i - 1] > height[i]) {
                return false;
            }
        }
        return true;
    }

    private static int[] removeStudents(int[] height) {
        List<Integer> newList = new ArrayList<>();
        newList.add(height[0]);
        for (int i = 1; i < height.length; i++) {
            if (height[i - 1] <= height[i]) {
                newList.add(height[i]);
            }
        }
        int[] newArray = new int[newList.size()];
        for (int i = 0; i < newList.size(); i++) {
            newArray[i] = newList.get(i);
        }
        return newArray;
    }
}
