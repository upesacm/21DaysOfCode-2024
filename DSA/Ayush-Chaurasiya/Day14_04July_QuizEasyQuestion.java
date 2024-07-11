import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        List<Integer> myList = new ArrayList<>();
        for(int i = 0; i < n; i++){
            myList.add(scanner.nextInt());
        }
        scanner.close();

        int moves = 0;
        boolean flag = true;
        while (flag) {
            flag = false;
            List<Integer> tempList = new ArrayList<>();
            tempList.add(myList.get(0)); // add the first element
            for (int i = 1; i < myList.size(); i++) {
                if (myList.get(i) >= myList.get(i - 1)) {
                    tempList.add(myList.get(i));
                } else {
                    flag = true;
                }
            }
            myList = tempList; // update myList
            if (flag) {
                moves++;
            }
        }

        System.out.println(moves);
    }
}
