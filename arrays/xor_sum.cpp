#include <iostream>

using namespace std;

int main(){

    string a = "";
    string b = "12";

    long long int numA = stoi(a);
    long long int numB =  stoi(b);

    int num,count=0;

    for (int i = numA; i <= numB; i++)
    {

        num=0;
        int n = i;
        int rem;
        int minNum=INT32_MAX,maxNum=INT32_MIN;
        while (n!=0)
        {
            rem = n%10;
            maxNum = max(rem,maxNum);
            minNum = min(rem,minNum);
            num^=rem;
            n/=10;
        }
        
        double avg = (maxNum+minNum)/2.0;
       // cout<<avg<<endl;
       if(num>avg)
       count++;

    }

   cout<<count;
    
    //TODO: Make an Optimized Solutuon

    // for (int i = 0; i < a.size(); i++)
    // {
    //     num ^= (int)a[i]-48;
    // }
    // int minNum=INT32_MAX,maxNum=INT32_MIN;

    // for (int i = 0; i < a.size(); i++)
    // {
    //    // cout<<"Yes";
    //         maxNum = max((int)a[i]-48,maxNum);
    //         minNum = min((int)a[i]-48,minNum);
    // }
    //     //cout<<maxNum<<endl;
    //     //cout<<minNum<<endl;
    // double avg = (maxNum+minNum)/2.0;


    return 0;
}
