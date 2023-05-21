#include<iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

  void solve(Node *root, int sum, int &maxSum, int length, int &maxLength){
        
        if(root==NULL){
            
            if(length>maxLength){
                
                maxLength = length;
                maxSum = sum;
            }else if(maxLength == length){
                
                maxSum = max(sum,maxSum);
            
            }
            
            return;
        }
        
        sum += root->data;
        
        solve(root->left,sum,maxSum,length+1,maxLength);
        solve(root->right,sum,maxSum,length+1,maxLength);
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int maxSum = INT32_MIN;
        int maxLength = INT32_MIN;
        
        solve(root,0,maxSum,0,maxLength);
        return maxSum;
        
    }