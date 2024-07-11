import java.util.Scanner;

public class Day3Question2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a String");
        String str = sc.nextLine();
        checkSymmetry(str);
        sc.close();
    }

    public static void checkSymmetry(String str) {
        str = str.toLowerCase();
        if (str == null || str.isEmpty()) {
            System.out.println("symmetrical");
            return;
        }
        
        
        int n = str.length();
        int[] diff = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            diff[i] = Math.abs(str.charAt(i) - str.charAt(i + 1));
        }
        
        for (int i = 0; i < diff.length / 2; i++) {
            if (diff[i] != diff[diff.length - 1 - i]) {
                System.out.println("not symmetrical");
                return;
            }
        }
        
        System.out.println("symmetrical");
    }
}
