#include <iostream>

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

int findMin(Node *root){

    Node *temp = root;
    while(temp->left!=NULL) temp = temp->left;

    return temp->data;
}

Node* deleteNode(Node *root,int x){

    if(root==NULL)
        return NULL;

    if(root->data==x){
        //4 cases
        Node *temp = root;
        if(root->left == NULL && root->right==NULL){
            delete temp;
            return NULL;
        }else if(root->left != NULL && root->right == NULL){
            temp = root->left;
            delete root;
            return temp;
        }else if (root->left==NULL && root->right != NULL){
            temp = root->right;
            delete root;
            return temp;
        }else{

            //We have two options, either get max from left subtree, or min from right subtree

            //Let's take min from right subtree

            int min = findMin(root->right);
            //Copy the min value to the current node
            root->data = min;

            root->right = deleteNode(root->right,min);
            
            return root;

        }

    }else if(x > root->data){
        root->right = deleteNode(root->right,x);

    }else{
        root->left = deleteNode(root->left,x);
    }
   
   return root;

}

void inorderTraversal(Node *root){

    if(root==NULL)
        return ;

    inorderTraversal(root->left);

    cout<<root->data<<" ";

    inorderTraversal(root->right);
}

void createTree(){

    //10 5 7 2 8 15 13 20 -1

    Node *root = NULL;

    while(1){
        int data;
        cout<<"Enter the data : ";
        cin>>data;
        if(data==-1)
            break;
        root = buildTree(root,data);

    }

    cout<<"\n";

    inorderTraversal(root);
    cout<<endl;
    deleteNode(root,8);
    inorderTraversal(root);
}

int main(){

    createTree();
    return 0;
}