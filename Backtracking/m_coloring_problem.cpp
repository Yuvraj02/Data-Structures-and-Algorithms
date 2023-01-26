#include <iostream>
#include <vector>
using namespace std;

bool isSafeToColor(int row,vector<vector<int>> &colorMatrix, int colorVal){

    for (int column = 0; column < colorMatrix[row].size(); column++)
    {
        if(colorMatrix[row][column]==colorVal) //Means this color is not safe
            return false;
    }
    
    return true;
}

void colorGraph(vector<vector<bool>>& graph,int row, vector<vector<int>> &colorMatrix, int colorVal){

    for (int column = 0; column < colorMatrix[row].size(); column++)
    {
        if(colorMatrix[row][column]==0 && graph[row][column]==1){
            colorMatrix[row][column]=colorVal;
            colorMatrix[column][row]=colorVal;
        }
    }
    
    //Color the particular Graph then
    colorMatrix[row][row]=colorVal;
}

void unColorGraph(vector<vector<bool>>& graph,int row, vector<vector<int>> &colorMatrix, int colorVal){

     for (int column = 0; column < colorMatrix[0].size(); column++)
    {
        if(colorMatrix[row][column]==0 && graph[row][column]==1){
            colorMatrix[row][column]=0;
            colorMatrix[column][row]=0;
        }
    }
    
    //Uncolor the Graph
    colorMatrix[row][row]=0;    

}

bool solve(vector<vector<bool>>& graph, vector<vector<int>> colorMatrix,int N, int totalColors){

    for (int row = 0; row < N; row++)
    {
        //If a particular graph is not yet coloured
        if(colorMatrix[row][row]==0)
            {
            for (int colorVal = 1; colorVal <=totalColors ; colorVal++)
                {
                    if(isSafeToColor(row,colorMatrix,colorVal)){
                        //Color the graph and keep track of other values
                        colorGraph(graph,row,colorMatrix,colorVal);
                        bool goingCorrect =  solve(graph,colorMatrix,N,totalColors);
                        if(goingCorrect)
                            return true;
                        else //Backtrack
                            unColorGraph(graph,row,colorMatrix,colorVal);
                    }
                }
                return false;
            }
        
    }
for (int i = 0; i < colorMatrix.size(); i++)
{
    cout<<colorMatrix[i][i]<<" ";
}

return true;

}

int main(){

    int N = 6;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4},{4,5},{5,0}};
    
    vector<vector<bool>> graph(N,vector<bool>(N,0));

    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]][edges[i][1]]=1;
        graph[edges[i][1]][edges[i][0]]=1;
        
    }

    // for(int i=0;i<graph.size();i++){
    //     for(int j=0;j<graph[i].size();j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<vector<int>> colorMatrix(N,vector<int>(N, 0));
    int M = 2;
    solve(graph,colorMatrix,N,M);      

    return 0;
}