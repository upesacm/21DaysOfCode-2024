# include<bits/stdc++.h>
using namespace std;

//This Function check the substring is palindrome or not
bool isPalindrome(const std::string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

//the time complexity of this function is about O(n2)
int checkPalindromicSubstrings(string str, int minLength){
    unordered_set<string> substring;
    int l=0;
    int r=minLength-1;
    while(r<str.size()){
        if(isPalindrome(str,l,r)){
            substring.insert(str.substr(l, r-l+1));
        }
        r++;
        l++;
    }
    return substring.size();
    
}

int main(){
    string str="abacab";
    int length=3;
    cout << checkPalindromicSubstrings(str,length);
    return 0;
}