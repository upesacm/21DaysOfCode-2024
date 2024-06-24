#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<string>v;
    string ch,str,str1;
    int len;
    cout<<"Enter string ch ";
    cin>>ch;
    cout<<"Enter substring length ";
    cin>>len;

    int i,j,k,count=0;
    for(i=0;i<ch.length();i++){
        for(j=0;j<ch.length();j++){
            str="";
            str1="";
            for(k=i;k<=j;k++){
                str=str+ch[k];
            }
            for(k=(str.length())-1;k>=0;k--){
                str1=str1+str[k];
            }
            for(k=0;k<v.size();k++){
                if(v[k]==str){
                    str="";
                }
            }
            if(str==str1 && str!="" && str1!="" && str.length()==len){
                v.push_back(str);
                cout<<str<<" "<<str1<<"\n";
                count++;
            }
        }
    }
    cout<<"count= "<<count;
    return 0;
}
