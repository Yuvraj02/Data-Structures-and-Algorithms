#include <iostream>
#include <vector>
using namespace std;

int main(){

        vector<int> B = {1,2,4};

        int xorSum=0;
        for (int i = 0; i < B.size(); i++)
        {
            xorSum^=B[i];
        }
           
   // }

    return 0;
}