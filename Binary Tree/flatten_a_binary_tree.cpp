#include <iostream>
#include <queue>
using namespace std;

/*

         5
        / \
       2   6
      / \   \
     3   4   8

5 2 6 3 4 -1 8 -1 -1 -1 -1 -1 -1
*/

class Node{
    public:
        Node *left;
        Node *right;
        int data;

        Node (int data){
            this->left = NULL;
            this->right = NULL;
            this->data = data;
        }
};

Node *buildTree(Node *root){

    queue<Node*> q;

    cout<<"Enter the Root : ";
    int data;
    cin>>data;
    cout<<"\n";
    if(data==-1)
        return NULL;

    root = new Node (data);

    q.push(root);

    while(!q.empty()){

        Node *front = q.front();
        q.pop();

        cout<<"Enter Left of "<<front->data<<": ";
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            front->left = new Node(leftData);
            q.push(front->left);
        }
        cout<<"\n";

        cout<<"Enter Right of "<<front->data<<": ";
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            front->right = new Node(rightData);
            q.push(front->right);
        }
        cout<<"\n";
    }
return root;
}

void preOrderTraversal(Node *root){

    if(root==NULL)
        return ;
    
    cout<<root->data<<" ";

    preOrderTraversal(root->left); 

    preOrderTraversal(root->right);
}


  void flatten(Node *root)
    {
        //code here
        Node *current = root;
        Node *pre = NULL;
        
        while(current){
            
            if(current->left==NULL){
                
                current = current->right;
            }else{
                
                pre = current->left;
                while(pre->right!=NULL && pre->right != current)
                    pre = pre->right;
                    
                if(pre->right==NULL){
                   // cout<<current->key<<" ";
                   //Important algo
                    pre->right = current->right;
                    current->right = current->left;
                    current->left = NULL;
                }else{
                    pre->right = NULL;
                    current = current->right;
                }
                
            }
            
        }
       // cout<<"\n";
    }

void print(Node *root){

   Node *curr = root;

   while(curr!=NULL){
    cout<<curr->data<<" ";
    curr=curr->right;
   }
}

int main(){

    Node *root = buildTree(root);
    cout<<"Preorder Traversal: ";
    preOrderTraversal(root);
    cout<<"\n";
    cout<<"Linked List : ";
    flatten(root);
    print(root);
    cout<<"\n";

    return 0;
}