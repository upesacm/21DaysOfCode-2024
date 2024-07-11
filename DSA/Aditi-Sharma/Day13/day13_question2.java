import java.util.*;
class ispalindrome
{
static int rev(int n, int temp)
{
	if (n == 0)
    {
        return temp;
    }
	temp = (temp * 10) + (n % 10);
	return rev(n / 10, temp);
}

public static void main (String[] args) 
{
    Scanner sc=new Scanner(System.in);
	int n = sc.nextInt();
	int temp = rev(n, 0);
	if (temp == n)
		System.out.println("yes");
	else
		System.out.println("no" );
}
}
