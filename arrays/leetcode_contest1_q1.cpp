#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int closetTarget(vector<string>& words, string target, int startIndex) {

    int i = startIndex,j=startIndex;
    int countFori=0,countForj=0;
   while (words[i]!=target)
   {
        i--;

        if(i==-1)
            i=words.size()-1;

        if(i==startIndex)
            break;

        countFori++;
   }
   
    while (words[j]!=target)
    {
        j++;

        if(j==words.size())
            j=0;

        if(j==startIndex)
            break;

        countForj++;
    }

    if(i==j && j==startIndex)
        return -1;
    
    return min(countFori,countForj);
}

int main(){
vector<string> words = {""};
string target = "pbgjhutcwb";
int startIndex = 0;

cout<<closetTarget(words,target,startIndex);

}