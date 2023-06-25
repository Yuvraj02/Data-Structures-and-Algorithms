#include <iostream>
#include <stack>
#include <queue>

using namespace std;
class Node{
    public:
        Node *left;
        Node *right;
        int data;

        Node(int data){
            this->right = NULL;
            this->left = NULL;
            this->data = data;
        }
};

Node *buildTree(Node *root){
    cout<<"Enter the data : ";
    int data;
    cin>>data;
    
    if(data==-1)
        return NULL;
    
    root = new Node(data);

    cout<<"Going to the left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Going to the right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void reverse(Node *root){

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);

    while(!q.empty()){
        Node *front = q.front();
        q.pop();
        s.push(front);

        if(front->right)
            q.push(front->right);
        
        if(front->left)
            q.push(front->left);
    }
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

int main(){
    
    Node *root = NULL;
    root = buildTree(root);
    //1 3 -1 -1 2 -1 -1
    /*
            1
           / \
          2   3

     Print : 3 2 1     
    */
    cout<<"\n";
    reverse(root);
    return 0;
}