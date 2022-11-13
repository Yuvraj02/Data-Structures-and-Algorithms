#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while (t--)
    {
            int n,s,count=0;
            cin>>n>>s;
            //Maximum Tastiness = n, Sum = S
            int maxVal = 0;
            for (int i = 0; i < n; i++)
            {
                if(s-i<=n && s-i>=0) {
                    maxVal = max(maxVal,abs(i-(s-i)));
                }
            }
            
    cout<<maxVal<<endl;
    }
    

    return 0;
}