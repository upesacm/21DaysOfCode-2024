// Given an array of integers and an integer k, determine the number of (i, j) pairs where i \< j and the sum of the pair is divisible by k.


public static int countPairs(int[]arr, int k){
    int count=0;
    for(int i=0;i<arr.length;i++){
            for(int j=i+1;j<arr.length;j++){
                if ((arr[i]+arr[j])%k==0) {
                    count++;
                }
        }
}
return count;
}


