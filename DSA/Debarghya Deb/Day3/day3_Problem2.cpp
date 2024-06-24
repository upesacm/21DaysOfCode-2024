#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;



 bool check(string input, map <char, int> alphabets, vector <char> places, string compare){

    for (int i = 0; i < input.size(); i++)
        {
           
           int position = alphabets[input[i]];
           int rev_pos =  26 - position + 1   ;
           input[i] = places[rev_pos - 1]; 
        
        }
    
    
        if(input == compare){
            return true;
        }
        
        return false;
    }
 



int main(){

   
    

    map <char, int> alphabets = { 
        {'a' , 1} , 
        {'b' , 2} , 
        {'c' , 3} , 
        {'d' , 4} , 
        {'e' , 5} ,  
        {'f' , 6} ,
        {'g' , 7} , 
        {'h' , 8} ,
        {'i' , 9} , 
        {'j' , 10} , 
        {'k' , 11} , 
        {'l' , 12} ,
        {'m' , 13} ,
        {'n' , 14} ,
        {'o' , 15} , 
        {'p' , 16} , 
        {'q' , 17} , 
        {'r' , 18} , 
        {'s' , 19} , 
        {'t' , 20} , 
        {'u' , 21} , 
        {'v' , 22} , 
        {'w' , 23} , 
        {'x' , 24} , 
        {'y' , 25} , 
        {'z' , 26}  
         
         };

        vector <char> places = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'  };


        string input;
        cout<<"Enter the string please : " << endl;
        getline(cin, input);

        
        input.erase(remove(input.begin(), input.end(), ' '), input.end()); 
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        string compare = input;
        reverse(input.begin() , input.end() );
        
        if(check(input, alphabets, places, compare)){
            cout<< "symmetrical" << endl;
        }
        else{
            cout<< "not symmetrical" << endl;
        }

        
        


    return 0;
}