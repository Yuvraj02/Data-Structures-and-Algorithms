#include <iostream>

using namespace std;

/* Method 1 :

void printreverseString(string s,int n){

    if(n==0){
        cout<<s[0]<<endl;
        return;
    } 

    cout<<s[n];  
    printreverseString(s, n-1);
}
*/

// Method 2 :


// void printreverseString(string s,int n){

//         if(n==s.size()-1){
//             cout<<s[n];
//             return;
//         }
//         printreverseString(s,n+1);
//         cout<<s[n];
// }

//Method 3:
//Pass by reference
void reverseString(string &s,int a){

    if(a>(s.size()-1)-a){
        return ;
    }

    swap(s[a],s[(s.size()-1)-a]);
    reverseString(s,a+1);

}


int main(){

    string s = "Yuvraj";
   // cout<<s.size();

    reverseString(s,0);

    cout<<s;
    return 0;
}

