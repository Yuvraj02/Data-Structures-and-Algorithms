#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

template <typename T>
class BinaryTreeNode{

    public:
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        T data;
    
    BinaryTreeNode(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorderTraversal(BinaryTreeNode<int>* root,vector<int> &arr){

    if(root==NULL)
        return;

    inorderTraversal(root->left, arr);

    arr.push_back(root->data);

    inorderTraversal(root->right, arr);
}


bool twoSumInBST(BinaryTreeNode<int>* root, int target) {	
//     vector<int> arr;
//     inorderTraversal(root, arr);
//     int left = 0,right=arr.size()-1;

//     while(left<right){

//         int sum = arr[left] + arr[right];

//         if(sum < target)
//             left++;
//         else if(sum > target)
//             right--;
//         else
//             return true;
//     }
// return false;
//Morris Traversal ---------------

    BinaryTreeNode<int> *curr = root;
    BinaryTreeNode<int> *pre = NULL;
    unordered_set<int> s;
    while(curr){
        
            if(!curr->left){
                
                if(s.count(curr->data))
                    return true;
                else
                    s.insert(target-curr->data);
                
                curr = curr->right;
            }else{
                pre = curr->left;
                while(pre->right!=NULL && pre->right!=curr)
                    pre = pre->right;
                
                if(pre->right==NULL){
                    pre->right = curr;
                    curr = curr->left;
                }else{
                    
                    if(s.count(curr->data))
                        return true;
                    else
                        s.insert(target-curr->data);

                    pre->right = NULL;
                    curr = curr->right;
                }

            }  

    }
    return false;
}