public class que1 {

    public static boolean Calculate(int[] arrival,int threshold)
    {
    	int n=arrival.length;
    	int count=0;
    	for(int i=0;i<n;i++)
    	{
    		if(arrival[i]<=0) count++;
    	}
    	if(count<threshold) return true;
    	return  false;
    }

    public static void main(String[] args) {
        int[] arr = {-1,-3,4,2};
        int k = 3;
        
        boolean result = Calculate(arr, k);
        if(result) System.out.println("Yes");
        else System.out.println("No");
    }
}
