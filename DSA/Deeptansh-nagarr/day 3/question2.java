public class Main {
    public static String isSymmetrical(String str) {
        char[] chars = str.toCharArray();
        int left = 0;
        int right = chars.length - 1;

        while (left < right) {
            if ((int) chars[left] != (int) chars[right]) {
                return "not symmetrical";
            }
            left++;
            right--;
        }
        return "symmetrical";
    }
    public static void main(String[] args) {
        String str = "acxz";
        System.out.println(isSymmetrical(str));
    }
}
