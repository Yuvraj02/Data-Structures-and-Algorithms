#include <iostream>
#include <stack>

using namespace std;

void solve(stack<int>&inputStack, int N, int count){

    if(count==N/2){
        inputStack.pop();
        return;
    }

    int topVal = inputStack.top();
    inputStack.pop();
    solve(inputStack,N,count+1);
    inputStack.push(topVal);
}

int main(){

    stack<int> inputStack;
    int N;
    cin>>N;
        for (int i = 0; i < N+1; i++){
            int elem;
            cin>>elem;
            inputStack.push(elem);
        }
        
    solve(inputStack,N,0);
    //cout<<inputStack.size();
    while (!inputStack.empty())
    {
        cout<<inputStack.top()<<" ";
        inputStack.pop();
    }

}

//Bruteforce Approach
// void deleteMiddle(stack<int>&inputStack, int N){
//    // Write your code here
//     stack<int> other;
//     int mid = (N/2)+1;

//     for (int i = 0; i < mid; i++)
//     {
//         other.push(inputStack.top());
//         inputStack.pop();
//     }
    
//     other.pop();

//     while (!other.empty())
//     {
//         inputStack.push(other.top());
//         other.pop();
//     }
// }