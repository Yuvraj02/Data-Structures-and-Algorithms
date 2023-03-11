#include <iostream>
#include <vector>
using namespace std;

class petrolPump{
    public:
        int petrol;
        int distance;
};

int tour(vector<petrolPump> p, int n){

    int start=0;
    int balance = 0;
    int deficit=0;

    for(int i=0;i<n;i++){

        balance += p[i].petrol - p[i].distance;

        if(balance < 0){
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }

    if(deficit+balance >=0)
        return start;
    else
        return -1;
}


int main(){

    int n;
    cin>>n;
    vector<petrolPump> p(n);
    for (int i = 0; i < n; i++)
        cin>>p[i].petrol>>p[i].distance;
    


    return 0;
}