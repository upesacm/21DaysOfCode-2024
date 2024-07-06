import java.util.*;

public class Solution {

    public static int minMovesToSort(int[] heights) {
        int moves = 0;
        boolean sorted = false;

        while (!sorted) {
            sorted = true;
            List<Integer> toRemove = new ArrayList<>();

            for (int i = 1; i < heights.length; i++) {
                if (heights[i] < heights[i - 1]) {
                    toRemove.add(i);
                }
            }

            if (!toRemove.isEmpty()) {
                sorted = false;
                for (int i = toRemove.size() - 1; i >= 0; i--) {
                    int index = toRemove.get(i);
                    heights = removeElement(heights, index);
                }
                moves++;
            }
        }

        return moves;
    }

    private static int[] removeElement(int[] arr, int index) {
        if (arr == null || index < 0 || index >= arr.length) {
            return arr;
        }

        int[] newArr = new int[arr.length - 1];
        for (int i = 0, j = 0; i < arr.length; i++) {
            if (i == index) {
                continue;
            }
            newArr[j++] = arr[i];
        }

        return newArr;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = sc.nextInt();
        }

        int result = minMovesToSort(heights);
        System.out.println(result);
    }
}
