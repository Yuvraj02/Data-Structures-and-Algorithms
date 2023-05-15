#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void bfs(Node *root){

    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {        
        //Exploit the first node
        Node *front = q.front();
        
        q.pop();
        
        if(front==NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }else{
        
        cout<<front->data<<" ";
        
        if(front->left)
            q.push(front->left);

        if(front->right)
            q.push(front->right);
        }
    }

   
}

Node *buildTree(Node *root){

    cout<<" Enter the data : ";
    int data;
    cin>>data;

    if(data==-1)
        return NULL;

    root = new Node(data); //root is a pointer

    cout<<"Enter to the Left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter to the right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}


int main(){

    Node *root = NULL;
    root = buildTree(root);
    // 5 7 3 -1 -1 5 -1 -1 11 4 -1 -1 12 -1 -1
    cout<<endl;
    bfs(root);

    return 0;
}