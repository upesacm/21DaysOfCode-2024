public class Day8_1 {
    public static int maximumPossibleHeight(int[] stack1, int[] stack2, int[] stack3, int n1, int n2, int n3) {
        int sumStack1 = 0, sumStack2 = 0, sumStack3 = 0;
        for (int i = 0; i < n1; i++){
            sumStack1 += stack1[i];
        }
        for (int i = 0; i < n2; i++){
            sumStack2 += stack2[i];
        }
        for (int i = 0; i < n3; i++){
            sumStack3 += stack3[i];
        }
        int i = 0, j = 0, k = 0;

        while (true) {
            if (i == n1 || j == n2 || k == n3){ 
                return 0;
            }
            if (sumStack1 == sumStack2 && sumStack2 == sumStack3){ 
                return sumStack1;
            }
            if (sumStack1 > sumStack2 && sumStack1 > sumStack3) {
                sumStack1 -= stack1[i];
                i++;
            } else if (sumStack2 > sumStack1 && sumStack2 > sumStack3) {
                sumStack2 -= stack2[j];
                j++;
            } else {
                sumStack3 -= stack3[k];
                k++;
            }
        }
    }

    public static void main(String[] args) {
        int[] stack1 = {3, 2, 1, 1, 1};
        int[] stack2 = {4, 3, 2};
        int[] stack3 = {1, 1, 4, 1};
        int n1 = stack1.length;
        int n2 = stack2.length;
        int n3 = stack3.length;

        int ans = maximumPossibleHeight(stack1, stack2, stack3, n1, n2, n3);
        System.out.println("The maximum possible height of all the three stacks is: " + ans);
    }
}
