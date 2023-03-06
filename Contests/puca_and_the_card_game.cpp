#include <vector>
#include <iostream>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    
    for(int i=0; i < n; i++){
        cin>>a[i];
    }
    int pucca = 0,garu = 0;
    
    int i=0,j=n-1;
    int k = 1;
    while(i<=j){
        if(k%2==1){
                if(a[i] >= a[j]){
                    pucca += a[i];
                    i++;
                }else{
                    pucca +=a[j];
                    j--;
                }
        }else{
            if(a[i] >= a[j]){
                garu+=a[i];
                i++;
            }else{
                garu+=a[j];
                j--;
            }
        }
        k++;
    }
    
    if(pucca>=garu)
        cout<<"Pucca";
    else
        cout<<"Garu";
    
    return 0;
}