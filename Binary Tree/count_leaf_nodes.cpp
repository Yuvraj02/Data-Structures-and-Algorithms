#include <iostream>
#include <queue>

using namespace std;

class Node{

    public:
        int data;
        Node *left;
        Node *right;
    Node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }

};

void buildTree(Node* &root){

    int data;
    cout<<"Enter the data : ";
    cin>>data;
    cout<<endl;

    if(data==-1)
        return;
    
    root = new Node(data);

    cout<<"Going to the left of "<<root->data<<endl;
    buildTree(root->left);
    cout<<"Going to the Right of "<<root->data<<endl;
    buildTree(root->right);
}

int countLeafNodes(Node *root){
    queue<Node*> q;
    
    q.push(root);
    int count = 0;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if(front->left == NULL && front->right==NULL)
            count++;

        if(front->left)
            q.push(front->left);

        if(front->right)
            q.push(front->right);

    }
    
    return count;
}

int main(){
    Node *root = NULL;
    buildTree(root); 
    //1 2 -1 -1 3 -1 -1 
    /*
            1
           / \
          2   3
              
    */

    cout<<"No of Leaf Node present = "<<countLeafNodes(root);

    return 0;

}