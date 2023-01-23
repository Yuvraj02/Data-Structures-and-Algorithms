#include <iostream>
#include <vector>

using namespace std;

bool canPlaceVertically(vector<vector<char>> &puzzle, int row, int column, string word){

    int n = puzzle.size();
    //For upwards
    if(row-1>=0 && puzzle[row-1][column]!='+'){
        return false;
    }else if(row+word.size()<n && puzzle[row+word.size()][column]!='+')
        return false;

    for (int i = 0; i < word.size(); i++)
    {      
        if(row+i>=n) 
            return false;

        if((puzzle[row+i][column]==word[i] || puzzle[row+i][column]=='-')){
            continue;
        }else{
            return false;
        }  
    }
    
    return true;
}

bool canPlaceHorizontally(vector<vector<char>> &puzzle, int row, int column, string word){

    int n = puzzle.size();


    //For  Left side
    if(column-1>=0 && puzzle[row][column-1]!='+'){
        return false;
    }else if(column+word.size()<n && puzzle[row][column+word.size()]!='+'){
        return false;
    }

    for (int i = 0; i < word.size(); i++)
    {       
        if(column+i >= n)
            return false;

        if((puzzle[row][column+i]==word[i] || puzzle[row][column+i]=='-')){
            continue;
        }else{
            return false;
        }
            
    }
    
    return true;
}

vector<bool> placeVertically(vector<vector<char>>&puzzle, int row,int column ,string word){
    vector<bool> canBackTrack(word.size(),false);
    for(int i=0;i<word.size();i++){
        if(puzzle[row+i][column]=='-'){
            puzzle[row+i][column]=word[i];
            canBackTrack[i]=true;
        }
    }

    return canBackTrack;
}

vector<bool> placeHorizontally(vector<vector<char>>&puzzle, int row,int column ,string word){
    vector<bool> canBackTrack(word.size(),false);
    for(int i=0;i<word.size();i++){
        if(puzzle[row][column+i]=='-'){
            puzzle[row][column+i]=word[i];
            canBackTrack[i]=true;
        }
    }

    return canBackTrack;
}

void unPlaceVertically(vector<vector<char>>&puzzle, int row, int column, string word,vector<bool> canBackTrack){

        for (int i = 0; i < word.size(); i++)
        {
            if(canBackTrack[i]==true)
                puzzle[row+i][column] = '-';
        }
        
}

void unPlaceHorizontally(vector<vector<char>>&puzzle, int row, int column, string word,vector<bool> canBackTrack){

        for (int i = 0; i < word.size(); i++)
        {
            if(canBackTrack[i]==true)
                puzzle[row][column+i] = '-';
        }
}

void solve(vector<vector<char>>&puzzle, vector<string> words, int currentWord){

if(currentWord==words.size()){

    for(int i=0;i<puzzle.size();i++){
        for (int j = 0; j < puzzle.size(); j++)
        {
            cout<<puzzle[i][j]<<" ";
        }
        cout<<endl;
    }

    return;
}

int n = puzzle.size();
string word = words[currentWord];
for (int row = 0; row < n; row++)
{
    for (int column = 0; column < n; column++)
    {
        if(puzzle[row][column]=='-' || puzzle[row][column]==word[0]){
            if(canPlaceVertically(puzzle,row,column,word)){
            vector<bool> canBackTrack = placeVertically(puzzle,row,column,word);
            solve(puzzle,words,currentWord+1);
            unPlaceVertically(puzzle,row,column,word,canBackTrack);
        }

        if(canPlaceHorizontally(puzzle,row,column,word)){
            vector<bool> canBackTrack = placeHorizontally(puzzle,row,column,word);
            solve(puzzle,words,currentWord+1);
            unPlaceHorizontally(puzzle,row,column,word,canBackTrack);
        }

        }
        
    }
}

}

int main(){

vector<vector<char>> puzzle= {{'+','-','+','+','+','+','+','+','+','+'},
                              {'+','-','+','+','+','+','+','+','+','+'},
                              {'+','-','+','+','+','+','+','+','+','+'},
                              {'+','-','-','-','-','-','+','+','+','+'},
                              {'+','-','+','+','+','-','+','+','+','+'},
                              {'+','-','+','+','+','-','+','+','+','+'},
                              {'+','+','+','+','+','-','+','+','+','+'},
                              {'+','+','-','-','-','-','-','-','+','+'},
                              {'+','+','+','+','+','-','+','+','+','+'},
                              {'+','+','+','+','+','-','+','+','+','+'}};

    vector<string> words = {"LONDON","DELHI","ICELAND","ANKARA"};

    solve(puzzle,words,0);

    for(auto i : words){
      cout<<i<<" ";  
    }

    return 0;
}