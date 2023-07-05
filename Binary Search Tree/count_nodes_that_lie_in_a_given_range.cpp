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

    void countNodes(Node *root, int &l, int &h, int &count){
        
        if(!root)
            return ;
            
        if(root->data >=l && root->data <=h)
            count++;
        
        countNodes(root->left, l, h, count);
        countNodes(root->right,l,h,count);
    }

    int getCount(Node *root, int l, int h)
    {
      // your code goes here 
     int count = 0;      
      countNodes(root,l,h,count);
      return count;
    }