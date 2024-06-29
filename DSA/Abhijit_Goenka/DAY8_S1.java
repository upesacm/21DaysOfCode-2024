import java.util.Arrays;
import java.util.List;
import java.util.Stack;
import java.util.*;
class DAY8_S1
{
    public static void main(String[] args) 
    {
        List<Integer> stack1 = Arrays.asList(3, 2, 1, 1, 1);
        List<Integer> stack2 = Arrays.asList(4, 3, 2);
        List<Integer> stack3 = Arrays.asList(1, 1, 4, 1);

        System.out.println(maxEqualHeight(stack1, stack2, stack3));
    }
    public static int maxEqualHeight(List<Integer> stack1, List<Integer> stack2, List<Integer> stack3) 
    {
        int sum1 = stack1.stream().mapToInt(Integer::intValue).sum();
        int sum2 = stack2.stream().mapToInt(Integer::intValue).sum();
        int sum3 = stack3.stream().mapToInt(Integer::intValue).sum();
        int i = 0, j = 0, k = 0;
        while (i < stack1.size() && j < stack2.size() && k < stack3.size()) 
        {

            if (sum1 == sum2 && sum2 == sum3) 
            {
                return sum1;
            }

            if (sum1 >= sum2 && sum1 >= sum3) 
            {
                sum1 -= stack1.get(i++);
            } else if (sum2 >= sum1 && sum2 >= sum3) 
            {
                sum2 -= stack2.get(j++);
            } else if (sum3 >= sum1 && sum3 >= sum2) 
            {
                sum3 -= stack3.get(k++);
            }
        }

        return 0;
    }
}
