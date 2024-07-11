/*
 A professor has a class of students and wants to know if the class should be cancelled based on student arrival times. The class is cancelled if fewer than a threshold number of students arrive on time.
Inputs:
An integer representing the threshold number of students.
An array of integers representing arrival times, where a non-positive integer indicates on-time arrival. Output:
YES" if the class is cancelled, "NO" otherwise.
Example:
threshold = 3

arrival_times = [-1, -3, 4, 2]

Output: YES
 */

import java.util.*;
class DAY2_S1
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int threshold,studentnumber;
        int ontime=0;
        threshold=sc.nextInt();
        studentnumber=sc.nextInt();
        int arrivals[]=new int[studentnumber];
        for(int i=0;i<studentnumber;i++)
        {
            arrivals[i]=sc.nextInt();
        }
        for(int arrivaltime:arrivals)
        {
            if(arrivaltime>=0)
            {
                ontime++;
            }

        }
        if(ontime<threshold)
        {
            System.out.println("YES");
        }
        else{
            System.out.println("No");

        }
        

    }
}
