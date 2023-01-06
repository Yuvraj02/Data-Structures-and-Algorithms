#include <iostream>
#include <vector>

using namespace std;


int main(){

    vector<vector<int>> A = {{1,2,3,4},
                             {5,6,7,8},
                             {9,10,11,12},
                             {13,14,15,16},
                             {17,18,19,20}};

    //Print for rows first

    int rows = A.size();
    int columns = A[0].size();

    //First print from rows
    for (int k = 0; k < rows; k++)
    {
        int j=0,i=k;
        while (i>=0 && j<columns)
        {
            cout<<A[i][j]<<" ";
            i--;
            j++;
        }
        cout<<"\n";
    }

    //Print from columns

    for (int k = 1; k < columns; k++)
    {
        
        int j=k,i=rows-1;

        while (i>=0 && j<columns)
        {
            cout<<A[i][j]<<" ";
            i--;
            j++;
        }
        cout<<"\n";

    }
    
    

    return 0;
}