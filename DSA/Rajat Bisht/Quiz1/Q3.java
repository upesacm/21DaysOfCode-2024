import java.io.*;
import java.util.*;

public class Solution {
    
     static void offerMax(PriorityQueue<Integer> pq, int val, int maxVal) {
        pq.offer(Math.min(val, maxVal));
    }
    
    public static long minAmt(int n, int[] station, int p) {
        Arrays.sort(station);
        
        long cost = 0;
        
        long offset = 0;
        long houseOffset = 0;
        
        PriorityQueue<Integer> intervals = new PriorityQueue<>();
         
        offerMax(intervals, Integer.MAX_VALUE, p);
        offerMax(intervals, Integer.MAX_VALUE, p);
        
        for(int i = 0; i < station.length - 1; i++) {
            int numOfHousesInBw = station[i + 1] - station[i] - 1;
        
            offerMax(intervals, numOfHousesInBw / 2 + numOfHousesInBw % 2, p);
            
            if(numOfHousesInBw / 2 != 0) 
                offerMax(intervals, numOfHousesInBw / 2, p);
        }
        
        // System.out.println(intervals);
        
        while(p != 0) {
            long numOfDir = intervals.size();
            
            long numOfHouses = intervals.poll() - offset;
            
            // System.out.println(p);
            
            if(numOfHouses > 0) {
                if(p >= numOfHouses * numOfDir) {
                    // System.out.println("hello");
                    cost += (
                        numOfDir 
                        * (
                            (numOfHouses * (numOfHouses + 1)) / 2 
                            + numOfHouses * houseOffset
                        )
                    );
                    
                    p -= (int)(numOfHouses * numOfDir);
                    offset += numOfHouses;
                    houseOffset += numOfHouses;
                }
                else {
                    long low = 0;
                    long high = numOfHouses;
                    
                    long housesToTake = 0;
                    
                    while(low <= high) {
                        long mid = (low + high) / 2;
                        
                        if(mid * numOfDir <= p) {
                            housesToTake = Math.max(
                                mid,
                                housesToTake
                            );
                            
                            low = mid + 1;
                        }
                        else {
                            high = mid - 1;
                        }
                    }
                    
                    // System.out.println(housesToTake);
                
                    cost += (
                        numOfDir 
                        * (
                            (housesToTake * (housesToTake + 1)) / 2 
                            + housesToTake * houseOffset
                        )
                    );
                    
                    // System.out.printf("cost: %d", cost);
                    
                    p -= housesToTake * numOfDir;
                    offset += housesToTake;
                    houseOffset += housesToTake;
                    
                    // System.out.println(p);
                    
                    cost += p * (houseOffset + 1);
                    p -= p;
                }
            }
        }
    
        return cost;
    }
    public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int n= scan.nextInt();
    int station[]=new int[n];
    for(int i=0;i<n;i++){
        station[i]=scan.nextInt();
    }
    int p = scan.nextInt();
    System.out.println(minAmt(n,station,p));
    }
}
