class Day_1_Question_1 {
    public static int validSegments(int candy[], int day, int month) {
        int leftIndex = 0;
        int rightIndex = month-1;
        int segCount = 0;
        
        while (rightIndex < candy.length) {
            int sum = 0;
            for (int i=leftIndex; i <=rightIndex; i++)
                sum += candy[i];
            
            if (sum == day)
                ++segCount;
            
            ++leftIndex;
            ++rightIndex;
        }
        return segCount;
    }
    
    public static void main(String[] args) {
        int []candy = {2, 2, 1, 3, 2};
        System.out.println(validSegments(candy, 4, 2));
    }
}