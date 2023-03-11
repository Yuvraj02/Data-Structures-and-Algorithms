#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

string FirstNonRepeating(string A){
    unordered_map<char,int> count;

    queue<char> q;

    string finalString = "";
    for(int i=0; i<A.size();i++){
            count[A[i]]++;

            q.push(A[i]);

            while (!q.empty())
            {
                if(count[q.front()] > 1){
                    q.pop();
                }else{
                    finalString.push_back(A[i]);
                    break;
                }
            }
            
            if(q.empty())
                finalString.push_back('#');     
    }
		return finalString;   
}

int main(){
    string s = "aabcab";
    cout<<FirstNonRepeating(s)<<endl;

    return 0;
}