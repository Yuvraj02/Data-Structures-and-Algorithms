#include <iostream>

using namespace std;

int maxIndex(int steps,int badIndex){

    int i=0;

    for (int k = 0,j=1; k < steps; k++,j++)
    {
        cout<<k<<" "<<j<<endl;

        if(i+j==badIndex){
            k--;
           
            continue;
        }
        i+=j;
    }

    return i;
}

int main(){

    int steps = 3;
    int badIndex = 3;

    cout<<maxIndex(steps,badIndex)<<endl;

    return 0;
}