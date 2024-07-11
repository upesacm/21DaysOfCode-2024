//Yash Gupta 500125397
public class Day_2_Q1 {
    public static void ShouldClassBeCancelled(int arrivaltimes[],int threshold)
    {
        int student_on_time=0;
        for(int i=0;i<arrivaltimes.length;i++)
        {
            if(arrivaltimes[i]<=0){student_on_time++;}
        }
        if(student_on_time<threshold){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    } 
    public static void main(String[] args) {
        // Test case - 1
        int case1[]={-1,-3, 4,2};
        int threshold=2;
        System.out.println("Output from test case-1");
        ShouldClassBeCancelled(case1, threshold);
        // Test case - 2
        int case2[]={-1,-3,0,-8,4,2};
        threshold=3;
        System.out.println("Output from test case-2");
        ShouldClassBeCancelled(case2,threshold);
        // Test case - 3
        int case3[]={-1,-3,0,-8,4,2};
        threshold=6;
        System.out.println("Output from test case-3");
        ShouldClassBeCancelled(case3,threshold);

    }
}
