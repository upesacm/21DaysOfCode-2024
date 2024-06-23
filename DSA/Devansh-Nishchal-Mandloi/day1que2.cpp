//A simple brute force solution where I have itereated over each element and checked for its complement in the remaining elements
//This results in a slightly greater complexity but is easy to write and understand!
#include<iostream>
#include<vector>

using namespace std;

class Solution{
   public:
      int divisiblePairs(vector<int> arr, int k){
         if(arr.empty() || k == 0)
            return 0;
         int count = 0;
         int n = arr.size();
         for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
               if ((arr[i] + arr[j]) % k == 0){
                  count++;
            }
         }
      }
      return count;
   }
};

int main(){
   int n = 0;
   cout << "Enter the size of the array" << endl;
   cin >> n;

   int k = 0;
   cout << "Enter the value of k" << endl;
   cin >> k;

   vector<int> arr(n);
   cout << "Enter the values of elements of the array" << endl;
   for (int i = 0; i < n; i++){
      cin >> arr[i];
   }

   Solution sol;
   int pairs = sol.divisiblePairs(arr, k);
   cout << "The number of pairs in arr which are divisible by k are: " << pairs;
   return 0;
}
