#include <iostream>
#include <queue>
using namespace std;

class Node {

    public:
        int data;
        Node *left,*right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right =NULL;
        }
};

void buildTree(Node* &root){

    std::cout<<"Enter the root Node : "<<endl;
    int data;
    std::cin>>data;
    if(data==-1)
        return;
    
    root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        //Enter the data to the left
        std::cout<<"Enter data to left: ";
        int leftData;
        std::cin>>leftData;
        if(leftData!=-1){
            Node *leftNode = new Node(leftData);
            front->left = leftNode;
            q.push(leftNode);
        }

        //Enter Data to the right
        std::cout<<"Enter Data to the right : ";
        int rightData;
        std::cin>>rightData;
        if(rightData!=-1){
            Node *rightNode = new Node(rightData);
            front->right = rightNode;
            q.push(rightNode);
        }
    }

}

//Get depth of the Binary tree

int maxDepth(Node *root){

    if(!root)   
        return 0;
    
    int ls = 1 + maxDepth(root->left);
    int rs = 1 + maxDepth(root->right);

    return max(ls,rs);
}

// 3 9 20 -1 -1 15 7 -1 -1 -1 -1

/*
                3---------(1)
               / \
              9  20-------(2)
                /  \
               15   7-----(3)
       
*/      

//Height Should be 3
int main(){

    Node *root = NULL;
    buildTree(root);
    std::cout<<endl;
    std::cout<<maxDepth(root);

    return 0;
}