import java.util.*;
public class a8_q1 {
    public static void main(String[]args){
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter the lenght of 1st 2nd and 3rd stack");
        int len_s1 = sc.nextInt();
        int len_s2 = sc.nextInt();
        int len_s3 = sc.nextInt();
        int sumofstack[] = {0,0,0};
        int s1[] = new int[len_s1];
        int s2[] = new int[len_s2];
        int s3[] = new int[len_s3];
        int pointer[] = {0,0,0};

        System.out.println("Enter the  element first stack");
        for(int i= 0;i<len_s1; i++)
        {
            s1[i] = sc.nextInt();
            sumofstack[0]+=s1[i];
        }
        System.out.println("Enter the  element 2 stack");
        for(int i= 0;i<len_s2; i++)
        {
            s2[i] = sc.nextInt();
            sumofstack[1] += s2[i];
        }
        System.out.println("Enter the  element 3 stack");
        for(int i= 0;i<len_s3; i++)
        {
            s3[i] = sc.nextInt();
            sumofstack[2] += s3[i];
        }

        while (!(sumofstack[0] == sumofstack[1] && sumofstack[1]  == sumofstack[2])){
            if(sumofstack[0]>sumofstack[1] && sumofstack[0]>sumofstack[2]){
                sumofstack[0] = sumofstack[0] - s1[pointer[0]];
                pointer[0]++;
            }
            else if(sumofstack[1]>sumofstack[0] && sumofstack[1]>sumofstack[2]){
                sumofstack[1] = sumofstack[1] - s2[pointer[1]];
                pointer[1]++;
            }
            else{
                sumofstack[2] = sumofstack[2] - s3[pointer[2]];
                pointer[2]++;
            }
        }
        System.out.println("The Sum is = "+ sumofstack[0]);
     }
}
