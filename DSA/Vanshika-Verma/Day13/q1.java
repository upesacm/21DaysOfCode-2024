import java.util.Scanner;
public class Day13q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        if (palin(num)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
    public static boolean palin(int num) {
        String str = Integer.toString(num);
        return rec(str, 0, str.length() - 1);
    }
    private static boolean rec(String str, int left, int right) {
        if (left >= right) {
            return true;
        }
        if (str.charAt(left) != str.charAt(right)) {
            return false;
        }
        return rec(str, left + 1, right-1);
}
}
