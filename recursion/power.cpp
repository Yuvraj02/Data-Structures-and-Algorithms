#include <iostream>

using namespace std;

//  Method 1: 
// int power(int a,int b){

//     if(b==1){
//         return a;
//     }

//     return a * power(a,b-1);
// }


//Method 2:
int power(int a, int b){
    
    if(b==1)
        return a;
    if (b==0)
        return 1;
    
    //If odd
    if(b&1){
            return a * (power(a,b/2) * power(a,b/2));
    }else{
        return power(a,b/2) * power(a,b/2);
    }
}


int main(){

    cout<<power(3,11)<<endl;

    return 0;
}