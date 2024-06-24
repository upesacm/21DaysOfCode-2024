#include <bits/stdc++.h>
using namespace std;
#define all(x)(x).begin(),(x).end()
int main()
{
   string s;
   string to_find="abcdefghijklmnopqrstuvwxyz";
   getline(cin,s);
   transform(all(s),s.begin(),::tolower);
   sort(all(s));
   int j = 0;
   for(int i=0;i<s.size();i++){
    if(s[i]=to_find[j]){
        j++;
    }
   }

   if(j==26){
    cout<<"complete"<<endl;
   }
   else{
    cout<<"incomplete"<<endl;
   }
   return 0;
}
