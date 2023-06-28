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


//Optimized Approach
Node *buildOptimized(int &start, string &str){
    
    if(start>=str.size() || str.size()==0)
        return NULL;

    //Extract the number from string
    int num = 0;

    while(start < str.size() && isdigit(str[start])){
        num = num*10 + str[start] - '0';
        start++;
    }
    
    Node *root = NULL;
    //If num is not zero then only create a node, otherwise it means that the brackets were empty
    if(num>0)
        root = new Node(num);

    //If there's an opening bracket, then we will add left node first
    if(start<str.size() && str[start]=='('){
        //Increment start first for next node
        start++;
        root->left = buildOptimized(start,str);
    }
    //If there's a closing bracket, that means this is the end of left node, so return the node
    if(start<str.size() && str[start] == ')'){
        start++;
        return root;
    }

    //Now when we are done with left node, it's time for right node
    if(start<str.size() && str[start] == '('){
        start++;
        root->right = buildOptimized(start,str);
    }

    //If there's a closing bracket , then it means this is the end of right node so return the node
    if(start<str.size() && str[start]==')'){
        start++;
        return root;
    }

    //Finally return root
    return root;
}

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
    int start = 0;
    Node *root = buildOptimized(start,str);
    
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