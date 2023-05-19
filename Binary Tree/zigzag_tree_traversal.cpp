#include <iostream>
#include <vector>
#include <queue>

using namespace std;



struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(Node *root){

    cout<<"Enter Root : ";
    int data;
    cin>>data;
    cout<<"\n";
    if(data==-1)
        return NULL;

    root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        //Go left
        int leftData;
        cout<<"Enter the left child of "<<front->data<<" : ";
        cin>>leftData;
        cout<<endl;
        if(leftData!=-1){
            front->left = new Node(leftData);
            q.push(front->left);
        }

        //Go Right
        int rightData;
        cout<<"Enter the right child of "<<front->data<<" : ";
        cin>>rightData;
        cout<<endl;
        if(rightData!=-1){
            front->right = new Node(rightData);
            q.push(front->right);
        }

    }
    return root;
}
    
    vector<int> zigZag (Node *root){
        
        vector<int> res;
        
        queue<Node*> q;
        q.push(root);
        
        bool leftToRight = true;
        while(!q.empty()){
            
            int qsize = q.size();
            
            vector<int> ans(qsize);
            
            //This loop will traverse throuhh one level at a time
            for(int i=0;i<qsize;i++){
                
                Node *front = q.front();
                
                q.pop();
                
                int index = leftToRight ? i : qsize-i-1;
                
                ans[index] = front->data;
                
                if(front->left)
                    q.push(front->left);
                    
                if(front->right)
                    q.push(front->right);
            }
            
            
            for(auto i : ans){
                res.push_back(i);
            }
            
            leftToRight = !leftToRight;
        }
        
     return res;   
    }
    
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	return zigZag(root);
    }

int main(){

    Node *root = NULL;
    buildTree(root);


    return 0;
}
