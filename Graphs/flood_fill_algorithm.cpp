#include <iostream>
#include <vector>

using namespace std;

 bool isSafe(int x, int y,vector<vector<int>>& image){

        int row = image.size();
        int col = image[0].size();

        if((x>=0 && x<col) && (y>=0 && y<row))
            return true;

    return false;

    }

    void solve(int x, int y, int initColor, int color,vector<vector<int>>& image,int X[], int Y[]){

        image[y][x] = color;

        for(int i = 0;i < 4;i++){
            int newY = Y[i] + y;
            int newX = X[i] + x;

            if(isSafe(newX,newY,image) && image[newY][newX]==initColor && image[newY][newX]!=color){
                solve(newX,newY,initColor,color,image,X,Y);
            }

        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> helperImage = image;

        int X[] = {0,1,0,-1};
        int Y[] = {1,0,-1,0};

        int initColor = image[sr][sc];

        solve(sc, sr, initColor, color, helperImage,X,Y);
        return helperImage;
    }