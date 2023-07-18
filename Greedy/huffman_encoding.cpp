#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Node{
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
    
    class compare{
        public:
        
            bool operator()(Node *a, Node *b){
                return a->data > b->data;
            }
    };
    
    void preorder(Node *root,vector<string> &ans, string s){
       
       if(!root)
        return;
       
       if(!root->left && !root->right){
           
           ans.push_back(s);
           return;
       }
        
        preorder(root->left,ans,s+"0");
        preorder(root->right, ans,s+"1");
    }   
    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*,vector<Node*>,compare> minHeap;
		    
		    for(int i = 0; i<N;i++){
		        Node *newNode = new Node(f[i]);
		        minHeap.push(newNode);
		    }
		    
		    while(minHeap.size()>1){
		           
		          Node *left = minHeap.top();
		          minHeap.pop();
		          
		          Node *right = minHeap.top();
		          minHeap.pop();
		          
		          Node *newNode = new Node(left->data + right->data);
		          newNode->left  = left;
		          newNode->right = right;
		          minHeap.push(newNode);
		    }
		    
		    Node *root = minHeap.top();
		    vector<string> ans;
		    string s = "";
		    preorder(root,ans,s);
		    return ans;
		}