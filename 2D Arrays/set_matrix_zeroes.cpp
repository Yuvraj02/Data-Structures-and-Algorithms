#include <iostream>
#include <vector>

using namespace std;



int main(){
vector<vector<int>> A= {{0,1,2,0},
                        {3,4,5,2},
                        {1,3,1,5}};

 int rows = A.size(),columns = A[0].size(),col0=1;   

for (int i = 0; i < rows; i++)
{
    if(A[i][0]==0) col0=0;
    for (int j = 1; j < columns; j++)
    {
        if(A[i][j]==0){
            A[i][0]=A[0][j]=0;
        }
    }
}

    //Traverse from back

    for (int i = rows-1; i >=0 ; i--)
    {
        for (int j = columns-1; j >=1 ; j--)
        {
            //If any one of the particular element's dummy row and col index
            //is set to 0, then simply change it to 0
            if(A[i][0]==0 || A[0][j]==0) A[i][j]=0;
        }
        if(!col0) A[i][0]=0;
    }
    

     for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            
            cout<<A[i][j]<<" ";
        }   
        cout<<endl;
    }

}




//Bruteforce Solution------------------------------------------
// void setMatrixZeroes(vector<vector<int>>&A, int row,int column){

// //Set zeroes horizontally
// for(int i=0;i<A[row].size();i++)
// {
//     if(A[row][i] == 0)
//         continue;

//     A[row][i] = INT32_MIN;
// }
    

// //Set zeroes vertically

// for (int i = 0; i < A.size(); i++){
//     if(A[i][column] == 0)
//         continue;

//     A[i][column]=INT32_MIN;
// }
    
// }

// int main(){

//     vector<vector<int>> A= {{1,1,1},
//                            {1,0,1},
//                            {1,1,1}};


//     for (int i = 0; i < A.size(); i++)
//     {
//         for (int j = 0; j < A[i].size(); j++)
//         {
            
//             if(A[i][j]==0){
//                 setMatrixZeroes(A,i,j);
//             }

//         }   
//     }
    
//      for (int i = 0; i < A.size(); i++)
//     {
//         for (int j = 0; j < A[i].size(); j++)
//         {
            
//             if(A[i][j]==INT32_MIN)
//                 A[i][j]=0;
//         }   
//     }
    
//      for (int i = 0; i < A.size(); i++)
//     {
//         for (int j = 0; j < A[i].size(); j++)
//         {
            
//             cout<<A[i][j]<<" ";
//         }   
//         cout<<endl;
//     }

//     return 0;
// }