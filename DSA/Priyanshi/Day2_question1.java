import java.util.*;
public class Day2_question1 {
    public static String isClassCancelled(int threshold, int arrival[])
    {
        int timecount= 0;
        for (int atime : arrival)
        {
            if(atime<=0)
            {
                timecount++;
            }
        }
        return timecount < threshold? "YES" : "NO";
    }

public static void main(String args[])
{
    Scanner sc = new Scanner(System.in);
    int threshold = 0, n=0;

    System.out.println("Enter the threshold number of students: ");
    threshold = sc.nextInt();
    System.out.println("Enter the number of students: ");
    n = sc.nextInt();

    int arrival[] = new int[n];
    System.out.println("Enter the arrival time of the students:");
    for(int i=0;i<n;i++)
    arrival[i] = sc.nextInt();

    String result = isClassCancelled(threshold, arrival);
    System.out.println(result);
}
}
