#include <iostream>

using namespace std;

int sqrt(int target){

int start = 0,end=target,mid = start + (end-start)/2;
int ans=-1;
    while (start<=end)
    {
        if(mid*mid==target){
            return mid;
        }else if(mid*mid<target){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }

    return ans;
}

double getPrecision(int value, int precision, int tempSol){

    double factor = 1;
    double ans = tempSol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor/10;
        for(double j = ans;j*j<value;j+=factor){

            ans=j;
        }
    }
    return ans;

}


int main(){

    cout<<sqrt(8);
    cout<<getPrecision(8,3,2);

    return 0;
}