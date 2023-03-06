#include <vector>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    vector<int> a(n);
    
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    
    int ray=0, nee=0;
    int k = 1,i=0,j=n-1;
    while(i<=j){
        if(k%2==1){
            //Rayinshi's turn
            if(a[i] >= a[j]){
                ray += a[i];
                i++;
            }else{
                ray += a[j];
                j--;
            }
        }else{
            if(a[i] >= a[j]){
                nee += a[i];
                i++;
            }else{
                nee += a[j];
                j--;
            }
        }
        k++;
    }
    
    cout<<ray<<" "<<nee;
    return 0;
}
