#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void inorderTraversal(vector<int> &tree, int index,vector<int> &inorder){

    if(index>=tree.size())
        return;
    
    inorderTraversal(tree,2*index+1,inorder);

    inorder.push_back(tree[index]);

    inorderTraversal(tree,2*index+2, inorder);
}

int main(){

    vector<int> tree = {5,6,7,8,9,10,11};

    //Step 1: Construct inorder of this tree
    vector<int> inorder;
    inorderTraversal(tree,0,inorder);

    //Step 2 : As we know that inorder of BST is sorted, so perform min swaps to sort an array algorithm

    //1. Create a mapping of value with corresponding index
    vector<pair<int,int>> p;
    for(int i = 0; i<inorder.size();i++)
        p.push_back({inorder[i],i});

    sort(p.begin(),p.end());

    int count=0;

    for(int i = 0; i<p.size();i++){
        
        //If the value is not at it's correct position then send it to correct pos
        if(p[i].second!=i){
            swap(p[i], p[p[i].second]);
            count++;
            i--;
        }
    }
    cout<<count;

    return 0;
}