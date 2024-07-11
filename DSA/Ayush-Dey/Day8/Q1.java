// Question-1
// Author - Ayush Dey

// first input is of sizes of the three arrays 
//then the value in the arrays resp.

import java.io.*;
import java.util.*;

class Result {

    public static int equalStacks(List<Integer> h1, List<Integer> h2, List<Integer> h3) {
        int sum1 = 0, sum2 = 0, sum3 = 0;
        for (int height : h1) sum1 += height;
        for (int height : h2) sum2 += height;
        for (int height : h3) sum3 += height;

        int index1 = 0, index2 = 0, index3 = 0;

        while (true) {
            if (index1 == h1.size() || index2 == h2.size() || index3 == h3.size()) {
                return 0;
            }

            if (sum1 == sum2 && sum2 == sum3) {
                return sum1;
            }

            if (sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= h1.get(index1++);
            } else if (sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= h2.get(index2++);
            } else {
                sum3 -= h3.get(index3++);
            }
        }
    }
}

public class Q1 {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n1 = Integer.parseInt(firstMultipleInput[0]);
        int n2 = Integer.parseInt(firstMultipleInput[1]);
        int n3 = Integer.parseInt(firstMultipleInput[2]);

        String[] h1Temp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");
        List<Integer> h1 = new ArrayList<>();
        for (int i = 0; i < n1; i++) {
            int h1Item = Integer.parseInt(h1Temp[i]);
            h1.add(h1Item);
        }

        String[] h2Temp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");
        List<Integer> h2 = new ArrayList<>();
        for (int i = 0; i < n2; i++) {
            int h2Item = Integer.parseInt(h2Temp[i]);
            h2.add(h2Item);
        }

        String[] h3Temp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");
        List<Integer> h3 = new ArrayList<>();
        for (int i = 0; i < n3; i++) {
            int h3Item = Integer.parseInt(h3Temp[i]);
            h3.add(h3Item);
        }

        int result = Result.equalStacks(h1, h2, h3);

        System.out.println(result);

        bufferedReader.close();
    }
}
