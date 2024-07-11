#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool Solution(string sentence, unordered_map<char, int>umap ){
    for(int i = 0; i < sentence.size(); i++){
        umap[sentence[i]]++;
    }

    for(auto x : umap){
        if(x.second == 0){
            return false;
        }
    }

    return true;
}

int main(){
    unordered_map <char, int> umap;

    umap['a'] = 0;
    umap['b'] = 0;
    umap['c'] = 0;
    umap['d'] = 0;
    umap['e'] = 0;
    umap['f'] = 0;
    umap['g'] = 0;
    umap['h'] = 0;
    umap['i'] = 0;
    umap['j'] = 0;
    umap['k'] = 0;
    umap['l'] = 0;
    umap['m'] = 0;
    umap['n'] = 0;
    umap['o'] = 0;
    umap['p'] = 0;
    umap['q'] = 0;
    umap['r'] = 0;
    umap['s'] = 0;
    umap['t'] = 0;
    umap['u'] = 0;
    umap['v'] = 0;
    umap['w'] = 0;
    umap['x'] = 0;
    umap['y'] = 0;
    umap['z'] = 0;

    string sentence;
    cout<<"Enter the sequence here : ";
    cin>>sentence;
    //sentence = "The quick brown fox jumps over the lazy dog";
    getline(cin, sentence);
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
    remove(sentence.begin(), sentence.end(), ' ');

    bool solution = Solution(sentence, umap);

    if(solution){
        cout<<"complete" << endl;
    }
    else{
        cout<<"incomplete" << endl;
    }

    
    
    return 0;
}