  #include <iostream>
  
  using namespace std;

  template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };


TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	//Write your code here
    if(root==NULL)
        return NULL;

        if(root->data > p->data && root->data > q->data){
                return LCAinaBST(root->left, p, q);
        } 
        if(root->data < p->data && root->data < q->data){
                return LCAinaBST(root->right, p, q);
        } 
        
        return root;


    // while(root){

    //     if(root->data > p->data && root->data > q->data){
    //             root = root->left;
    //     } else if (root->data < p->data && root->data < q->data) {
    //       root = root->right;
    //     } else{
    //       return root;
    // }
    // }

}