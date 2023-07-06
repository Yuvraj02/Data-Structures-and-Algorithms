#include <iostream>
#include <vector>

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
    
    Node* insert(Node *root, int &suc,int &data){
        
        if(root==NULL){
            Node *newNode = new Node(data);
            return newNode;
        }
        //Here whenever we are going left, then it means, that successor is the root node (Obviously)
        if(data < root->data){
            suc = root->data;
            root->left = insert(root->left, suc, data);
        }else{
            root->right = insert(root->right,suc,data);
            
        }
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        /*
            Start from the right of the array and insert all elements one by one
            replace the element at that position with it's successor
        */            
        Node *root = NULL;
        for(int i = arr.size()-1; i>=0;i--){
            
            int suc = -1;
            
            root = insert(root,suc,arr[i]);
            
            arr[i] = suc;
        }
        
        return arr;
    }

int main(){

    vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    for(auto i :findLeastGreater(arr,arr.size()))
        cout<<i<<" ";

    return 0;
}