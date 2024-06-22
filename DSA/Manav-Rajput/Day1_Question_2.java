import java.util.Scanner;

class number
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, k, count = 0;
        System.out.println("Enter n:");
        n = sc.nextInt();
        System.out.println("Enter array of integers:");
        int arr[] = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = sc.nextInt();
        }
        System.out.print("k = ");
        k = sc.nextInt();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int sum = arr[i] + arr[j];
                if(sum % k == 0)
                {
                    count++;
                }
            }
        }
        System.out.println("Number of pairs = " + count);
    }
}
