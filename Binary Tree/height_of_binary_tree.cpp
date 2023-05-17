//{ Driver Code Starts
//Initial template for C++

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(Node *root)
{   
    cout<<"Enter the data : ";
    int data;
    cin>>data;
    if(data==-1)
        return NULL;

    root = new Node(data);

    root->left = buildTree(root->left);

    root->right = buildTree(root->right);

    return root;

}


    //Function to find the height of a binary tree.
    int solve(struct Node* node){
        
        if(node==NULL)
            return 0;
            
        int left = 1+solve(node->left);
        int right = 1+solve(node->right);
        
        return max(left,right);
        
    }
    
    int height(struct Node* node){
        // code here 
        // Node* root = node;
        // queue<Node* > q;
        // q.push(root);
        // q.push(NULL);
        
        // int count = 1;
        
        // while(!q.empty()){
            
        //     Node *front = q.front();
        //     q.pop();
            
        //     if(front==NULL){
        //             if(!q.empty()){
        //                 count++;
        //                 q.push(NULL);
        //             }
        //     }else{
                
        //         if(front->left){
        //             q.push(front->left);
        //         }
                
        //         if(front->right){
        //             q.push(front->right);
        //         }
                
        //     }
            
        // }
        
        // return count;
        return solve(node);
        
    }

//{ Driver Code Starts.
int main()
{

    //1 2 -1 -1 3 -1 -1

    Node *root = NULL;
    root = buildTree(root);
    cout<<"\n";
    cout<<solve(root);
   return 0;
}
// } Driver Code Ends