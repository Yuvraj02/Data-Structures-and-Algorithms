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

void inOrderTraversal(Node *root){

    if(root==NULL)
        return ;
    
    inOrderTraversal(root->left);

    cout<<root->data<<" ";

    inOrderTraversal(root->right);
}


void morrisTraversal(Node *root){

    Node *current = root;
    Node *predecssor = NULL;
    while(root!=NULL){

        if(current->left==NULL){
            cout<<current->data<<" ";
            current = current->right;
        }else{
            predecssor = current->left;
            while(predecssor->right!=NULL && predecssor->right!=current)
                predecssor = predecssor->right;
            
            if(predecssor->right==NULL){
                predecssor->right = current;
                current = current->left;
            }else{
                predecssor->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }

        }

    }

}


int main(){

    Node *root = buildTree(root);
    cout<<"Inorder Traversal: ";
    inOrderTraversal(root);
    cout<<"\n";
    cout<<"Morris Traversal : ";
    morrisTraversal(root);
    cout<<"\n";

    return 0;
}