#include <iostream>
#include <vector>

using namespace std;

int main(){


    int n,m;
    cin>>n>>m;
    
    vector<vector<char>> A(n,vector<char>(m,'X'));

    int top = 0,bottom = n-1,right=m-1,left=0;
    int dir=0;
    bool isCross = true;

    while (top<=bottom && left<=right)
    {
        if(dir==0){
            for (int i = left; i <=right ; i++)
            {
               if(isCross)
                A[top][i]='X';
                else
                A[top][i]='O'; 
            }
            top++;
            dir=1;
        }else if (dir==1){
            for (int i = top; i <= bottom; i++)
            {
                if(isCross)
                    A[i][right]='X';
                else
                    A[i][right]='O';
            }
            right--;
            dir=2;
        }else if(dir==2){
            for (int i = right; i >= left; i--)
            {
                if(isCross)
                    A[bottom][i]='X';
                else
                    A[bottom][i]='O';
            }
            bottom--;
            dir=3;
        }else if(dir==3){
            for (int i = bottom; i >= top; i--)
            {
                if(isCross)
                    A[i][left]='X';
                else
                    A[i][left]='O';
            }
            dir=0;
            isCross = !isCross;
            left++;
        }
        

    }
    

    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A[i].size(); j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    

  


    return 0;
}