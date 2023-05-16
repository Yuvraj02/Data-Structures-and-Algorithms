#include <iostream>
#include <queue>
using namespace std;


class Node{

    public:
        Node *left;
        Node *right;
        int data;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};


Node *buildTree(Node *root){

    queue<Node*> q;
    int data;
    cout<<"Enter Root Node : ";
    cin>>data;
    cout<<endl;

    if(data==-1)
        return NULL;

    root = new Node(data);

    q.push(root);

    while(!q.empty()){

        Node *front = q.front();
        q.pop();

        //For left
        cout<<"Enter the data to the left of "<<front->data<<" : ";
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            front->left = new Node(leftData);
            q.push(front->left);
        }
        cout<<"\n";        
        //For right
        cout<<"Enter the data to the right of "<<front->data<<" : ";
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

void print(Node *root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){

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

int main(){

    Node *root = NULL;
    root = buildTree(root);
    print(root);
    return 0;
}