#include<iostream>

using namespace std;

class Interval{
    public:
        int start;
        int end;
    Interval(){}

    Interval(int start, int end){
        this->start = start;
        this->end = end;
    }
};

class Node{
    public:
        int max;
        int start;
        int end;
        Node *left;
        Node *right;
        Node(Interval i){
            this->start = i.start;
            this->end = i.end;
            this->max = i.end; //Initially
            this->left = NULL;
            this->right = NULL;
        }
};

Node *insertInterval(Node *root, Interval i){

    if(root==NULL){
        Node *newNode = new Node(i);
        return newNode;
    }   

    if(i.start < root->start) //Then go left
        root->left = insertInterval(root->left, i);
    else
        root->right = insertInterval(root->right, i);

    //If root's max is less than interval's end, then update ancestors
    if(root->max < i.end)
        root->max = i.end;

    return root;
}

void traverse(Node *root){
    if(!root)
        return;

    traverse(root->left);

    cout<<"["<<root->start<<", "<<root->end<<"]"<<" Max is : "<<root->max<<endl;

    traverse(root->right);

}

bool ifOverlap(Interval i1, Interval i2){

    if(i1.start <= i2.end && i1.end >= i2.start)
        return true;
    
    return false;
}

bool searchOverlap(Node *root, Interval i){
    if(root==NULL)  
        return false;
    
    if(ifOverlap(Interval(root->start,root->end),i))
        return true;

    //If left exists and max of left is greater than low interval
    if(root->left && root->left->max >= i.start)
        return searchOverlap(root->left,i);
    
    return searchOverlap(root->right,i);
}

int main(){

    Interval i1(15,20);
    Node *root = new Node(i1);
    insertInterval(root,Interval(10,30));
    insertInterval(root,Interval(5,7));
    insertInterval(root,Interval(30,40));
    traverse(root);
    Interval i2 (6,7);
    cout<<searchOverlap(root,i2);

    return 0;
}