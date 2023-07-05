 #include <iostream>
 #include <vector>
 #include <unordered_map>
 #include <algorithm>

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

    //Bruteforce Approach : Follows (Building preorder from inorder)
 void getIndex(vector<int> &inorder, unordered_map<int,int> &mapp){
        
        for(int i = 0; i<inorder.size();i++)
            mapp[inorder[i]] = i;
            
    }
    
    Node *buildTree(int &i, int inStart, int inEnd,unordered_map<int,int> &mapp, int pre[], vector<int> &inorder){
        
        if(i>=inorder.size() || inStart > inEnd){
            return NULL;
        }        
        
        int element = pre[i++];
        Node *root = new Node(element);
        int inMid = mapp[element];
        
        root->left = buildTree(i,inStart,inMid-1, mapp, pre,inorder);
        root->right = buildTree(i, inMid+1, inEnd, mapp, pre,inorder);
        
        return root;
    }
    
    
    Node *bruteForce(int pre[], int size){
        
        vector<int> inorder;
        for(int i = 0; i<size;i++)
            inorder.push_back(pre[i]);
        
        sort(inorder.begin(),inorder.end());
        
        //Now we have inorder and pre order of the bst, so build it
        unordered_map<int,int> mapp;
        getIndex(inorder,mapp);        
        
        int index = 0;
        return buildTree(index, 0,size-1,mapp,pre,inorder);
        
    }
    
    
    //Optimized Approach: Uses preorder only with the help of RANGE (-INF, INF)
    Node *buildTree(int &i, int pre[], long min, long max,int &size){
        
        if(i>=size)
            return NULL;
            
        Node *root = NULL;
        int element = pre[i];

        //The element which is about to be inserted in the subtree should be in range
        //If it's not in range, then it means it is part of another subtree 
        if(element > min && element < max){
            
            //If in range then create a node
            root = new Node(element);
            //Increment the index
            i++;
            
            root->left = buildTree(i,pre,min,element,size);
            root->right = buildTree(i,pre,element,max,size);

        }
    return root;
    }

    Node* post_order(int pre[], int size)
    {   
        int i=0;
        
        return buildTree(i,pre,LONG_MIN,LONG_MAX,size);
    }