//A simple Cpp solution with time complexity of O(n) where n is the size of the vector "arrival"

#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution{
   public:
      string isCancelled(vector<int> arrival, int threshold){
         int count = threshold;
         int i = 0;
         while(count > 0 && i<arrival.size()){
            if(arrival[i] <= 0){
               count--;
            }
            i++;
         }
         if(count > 0){
            return "YES";
      }
      return "NO";
   }
};

int main(){
   cout << "Enter the size of array" << endl;
   int n;
   cin >> n;
   
   vector<int> arrival(n);
   cout << "Enter the values of elements of the array" << endl;
   for (int i = 0; i < n; i++){
      cin >> arrival[i];
   }

   int threshold;
   cout << "Enter the threshold value" << endl;
   cin >> threshold;

   Solution sol;
   string result = sol.isCancelled(arrival, threshold);

   cout << "Is class cancelled? : " << result << endl;
   return 0;
}
