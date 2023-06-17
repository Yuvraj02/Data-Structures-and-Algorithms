#include <iostream>
#include <vector>

using namespace std;

void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	   int  n = matrix.size();
	    for(int i = 0; i<n;i++){
	        for(int j = 0; j<n;j++){
	            if(matrix[i][j]==-1)
	                matrix[i][j]=1e9;
	               
	            if(i==j)
	                matrix[i][j]=0;
	        }
	    }
	    
	//Compute every distance via a node
	    for(int via = 0; via<n;via++){
	        for(int i = 0; i<n; i++){
	            for(int j = 0; j<n;j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    
	    for(int i = 0; i<n;i++){
	        for(int j = 0; j<n;j++){
	            if(matrix[i][j]==1e9)
	                matrix[i][j]=-1;
	        }
	    }
	}