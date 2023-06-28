#include <iostream>
#include <stack>

using namespace std;

class Node{

    public:
        Node *left,*right;
        int data;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }    
};

//Bruteforce Functions
Node* buildTree(int start, int end, string &str);
int getMidIndex(int start, int end, string &str);

void preorder(Node *root){

    if(root==NULL)
        return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    string str = "4(2(3)(1))(6(5))";

    /*
            4
           / \
          2   6 
         / \  / 
        3   1 5

    Preorder of tree : 4 2 3 1 6 5
    */

   /* Bruteforce Approch: Time O(N^2)
        ->The idea is to get left substring and then right substring
        ->Then add these to current node and perform the task recursively
        Step 1 : Get index of the left subtree using stack
        Step 2 : The right subtree will start from this index + 2 position
        Step 3 : Every time we create a subtree the range is from start+1 to end-1;
    */
   // Node * root = buildTree(0,str.size()-1,str);
    preorder(root);

    return 0;
}


int getMidIndex(int start, int end, string &str){

    if(start>end)
        return -1;

    stack<char> s;
    for(int i = start; i<=end;i++){
        if(str[i] == '(')
            s.push(str[i]);

        if(!s.empty() && (str[i]==')' && s.top()=='('))
            s.pop();

        if(s.empty())
            return i;
    }
    return -1;
}

Node *buildTree(int start, int end, string &str){

    if(start>end)
        return NULL;

    //Extract number
    int num = 0;
    while(start<=end && isdigit(str[start])){
        num = num*10 + str[start] - '0';
        start++;
    }

    //Create Node with this number
    Node *root = new  Node(num);

    int index = getMidIndex(start,end,str);

    if(index!=-1){
        root->left = buildTree(start+1, index-1, str);
        root->right = buildTree(index+2, end-1,str);
    }

    return root;
}