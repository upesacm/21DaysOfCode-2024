public class DualisticString {

    public static void main(String[] args) {
        String str = "yxyyyxyyx";
        System.out.println(minimumValue(str));  // Output: 1
        
        String str2 = "yxxyxxyxxyxxy";
        System.out.println(minimumValue(str2));  // Output: 3
    }

    public static int minimumValue(String str) {
        int n = str.length();
        int totalX = 0;
        int totalY = 0;

        for (char c : str.toCharArray()) {
            if (c == 'x') totalX++;
            if (c == 'y') totalY++;
        }

        int minValue = Integer.MAX_VALUE;
        int currentX = 0;
        int currentY = 0;

        for (int i = 0; i <= n; i++) {
            if (i > 0) {
                if (str.charAt(i - 1) == 'x') currentX++;
                if (str.charAt(i - 1) == 'y') currentY++;
            }

            int remainingX = totalX - currentX;
            int removedY = currentY;

            for (int j = n - 1; j >= i; j--) {
                if (str.charAt(j) == 'x') remainingX--;
                if (str.charAt(j) == 'y') removedY++;

                int maxCost = Math.max(remainingX, removedY);
                minValue = Math.min(minValue, maxCost);
            }
        }

        return minValue;
    }
}
