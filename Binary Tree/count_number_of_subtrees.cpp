#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *left,*right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
int getSum(Node *root, int X, int &count){
    
    if(!root)
        return 0;
        
    int leftSum = getSum(root->left, X, count);
    int rightSum = getSum(root->right, X, count);
    
    int sum = root->data+leftSum + rightSum;
    
    if(sum == X)
        count++;
        
    return sum;
    
}

int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	if(!root)
	    return 0;
	    
	int count = 0;
	
	int leftSum = getSum(root->left, X, count);
	int rightSum = getSum(root->right, X, count);
	
	int sum = root->data + leftSum + rightSum;
	
	if(sum==X)
	    count++;
	  
	  return count;
	
}