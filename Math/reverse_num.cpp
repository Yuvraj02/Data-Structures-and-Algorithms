#include <iostream>

using namespace std;


int reverse(int x) {
        
        int n = x;
        long long num = 0;

        while(n!=0){

            int rem = n%10;
            if(abs(num*10) > INT_MAX)
                return 0;
            num = num * 10 + rem;
            n/=10;
        }

        return (int) num;
    }

int main(){

    int n;
    cin>>n;
    cout<<reverse(n);

    return 0;
}