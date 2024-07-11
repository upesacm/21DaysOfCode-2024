#include <bits/stdc++.h>
using namespace std;
#define all(x)x.begin(),x.end()
char reverse_ascii(char c){
    if(c >='a' && c<='z'){
         return 'z'-(c-'a');
    }
    return c;
}
int main(){
     string s;
     getline(cin,s);
     string x = s;
     if(s.length()%2!=0){
         cout<<"not symmetrical"<< endl;
         return 0;
     }
     transform(all(s),s.begin(),::tolower);
    transform(all(s),s.begin(),::reverse_ascii);
    reverse(all(s));
    cout<<"reversed string - "<<s <<endl;
    for(int i=0;i<s.size();i++){
           if(s[i]!=x[i]){
            cout<< "not symmetrical" << endl;
            return 0;
           }
    }
    cout<<"symmetrical";
    return 0;
}
