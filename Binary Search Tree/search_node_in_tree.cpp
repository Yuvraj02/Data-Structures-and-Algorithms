#include <iostream>
#include <iomanip>

using namespace std;

class Node {

    public:
        Node *left;
        Node *right;
        int data;

        Node(int data){
            this->left = NULL;
            this->right = NULL;
            this->data = data;
        }
};

Node *buildTree(Node *root,int data){

    if(root==NULL){
        Node *newNode = new Node(data);
        return newNode;
    }

    if(data > root->data)
        root->right = buildTree(root->right,data);
    else
        root->left = buildTree(root->left,data);

    return root;
}

bool searchBST(Node *root, int x){

    if(root==NULL)
        return false;

    if(root->data == x)
        return true;

    if(x>root->data)
        return searchBST(root->right,x);
    else
        return searchBST(root->left,x);
    
}

void createTree(){

    Node *root = NULL;

    while(1){
        int data;
        cout<<"Enter the data : ";
        cin>>data;
        if(data==-1)
            break;
        root = buildTree(root,data);

    }

    
    cout<<"Enter The element to be searched : ";
    int x;
    cin>>x;
    cout<<endl;
    cout<<boolalpha<<searchBST(root,x);

}

int main(){

    createTree();
    return 0;
}