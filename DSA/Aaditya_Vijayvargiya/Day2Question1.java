public static void decision (int threshold, int[] arr,int n) {
    int count=0;
    for (int i = 0; i < arr.length; i++) {
        if (arr[i]<0) {
            count+=1;
        }            
    }
    if (threshold>count) {
        System.out.println("YES");
    }
    else
    System.out.println("NO");
}