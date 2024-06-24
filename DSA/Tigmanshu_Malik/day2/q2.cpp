#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

vector<int> calculateRanks(vector<int> board, vector<int> score){

    vector<int> rank;
    vector<int>::iterator i = board.begin(), j = i + 1;

    while(i != board.end() - 1){

        if(*i == *(i + 1)){

            while(*j != *i)
                j++;

            board.erase(i, j);
            j = i + 1;
        }

        else    
            i++;
    }

    for(int i = 0; i < score.size(); i++){

        int j = 0;

        while( j < board.size() && board[j] > score[i] )
            j++;

        rank.push_back(j + 1);        
        
    }

    return rank;
}

