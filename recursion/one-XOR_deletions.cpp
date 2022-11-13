#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a;
        vector<int> finalArr;
        int valXOR=0,count=0;

        for (int i = 0; i < n; i++)
        {
            int elem;
            cin>>elem;
            a.push_back(elem);
        }

        

        for (int i = 0; i < a.size()-1; i++)
        {
                int val = a[i]^a[i+1];
               cout<<val<<" ";              
        }


        //cout<<count<<endl;

        
        }
        
       return 0; 

}
