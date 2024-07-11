#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution{
public:
   string isValid(string& str){
      unordered_map<char, int> charCount;
      unordered_map<int, int> freqCount;

      for(auto& ch : str){
         charCount[ch]++;
      }

      for(auto& pair : charCount){
         freqCount[pair.second]++;
      }

      if(freqCount.size() == 1){
         return "Valid";
      }

      if(freqCount.size() == 2){
         auto it1 = freqCount.begin();
         auto it2 = ++freqCount.begin(); //basically the next element of the map "freqCount"

         int freq1 = it1->first;
         int count1 = it1->second;
         int freq2 = it2->second;
         int count2 = it2->second;

         if(freq1 == 1 && count1 == 1 || freq2 == 1 && count2 == 1){
            return "Valid";
         }

         if((abs(freq1 - freq2) == 1) && count1 == 1 || count2 == 1){
            return "Valid";
         }
      }
      return "Invalid";
   }
};

int main(){
   string str;
   cout << "Enter a string: ";
   cin >> str;
   Solution sol;
   cout << "The string is: " << sol.isValid(str) << endl;
   return 0;
}
