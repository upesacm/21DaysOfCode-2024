    import java.util.*;

    public class Day14_Solution1 {

        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);

            // Reading input
            int n = scanner.nextInt();
            int[] heights = new int[n];
            for (int i = 0; i < n; i++) {
                heights[i] = scanner.nextInt();
            }

            // Finding the minimum number of moves
            System.out.println(minimumMoves(heights));
        }

        private static int minimumMoves(int[] heights) {
            int moves = 0;

            while (!isNonDecreasing(heights)) {
                heights = removeInvalidStudents(heights);
                moves++;
            }

            return moves;
        }

        private static boolean isNonDecreasing(int[] heights) {
            for (int i = 1; i < heights.length; i++) {
                if (heights[i - 1] > heights[i]) {
                    return false;
                }
            }
            return true;
        }

        private static int[] removeInvalidStudents(int[] heights) {
            List<Integer> newHeights = new ArrayList<>();

            newHeights.add(heights[0]);
            for (int i = 1; i < heights.length; i++) {
                if (heights[i - 1] <= heights[i]) {
                    newHeights.add(heights[i]);
                }
            }

            // Converting list back to array
            int[] result = new int[newHeights.size()];
            for (int i = 0; i < newHeights.size(); i++) {
                result[i] = newHeights.get(i);
            }

            return result;
        }
    }


