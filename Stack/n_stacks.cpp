#include <iostream>
#include <stack>

using namespace std;

class NStack
{
public:

    int *arr;
    int *top;
    int *next;
    int n,s;
    int freeSlot;
    
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        
        //Initialize Top
        for(int i=0;i<n;i++)
            top[i] = -1;

        //Initialize next
        for(int i=0; i < s; i++)
            next[i] = i+1;

        next[s-1] = -1;

        freeSlot = 0;
    }

    bool push(int x, int m)
    {
        //Check for Stack overflow
        if(freeSlot == -1)
            return false;
        //1. Store freeslot Index
        int index = freeSlot;
        //2. Update free slot
        freeSlot = next[freeSlot];
        //3. Put element to stack
        arr[index] = x;
        //4. Update next free slot value to top's prev val
        next[index] = top[m-1];
        //5. Update top variable
        top[m-1] = index;

        return true;
    }

    int pop(int m)
    {
         //Check for stack underflow
         if(top[m-1]==-1)
            return -1;
        
        int index = top[m-1];
        top[m-1] = next[index]; //As next contains below index
        next[index] = freeSlot;
        freeSlot = index; // as it contains prev valie

        return arr[index];
    }
};

int main(){
    
    NStack s(4,8);
    s.push(1,1);
    s.push(4,1);
    s.push(2,1);   
    cout<<s.pop(1)<<endl;
    
    
    return 0;
}