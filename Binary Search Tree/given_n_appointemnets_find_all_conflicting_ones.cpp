#include <iostream>
#include <vector>

using namespace std;

class Interval{
    public :
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
        Interval i;
        int start;
        int end;
        int max;
        Node *left;
        Node *right;
        
        Node(){}
        Node(Interval i){
            this->i = i;
            this->start = i.start;
            this->end = i.end;
            this->max = i.end;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertInterval(Node *root, Interval &i){
    if(!root){
        Node *newNode = new Node(i);
        return newNode;
    }
    //If interval's start is less than root's start, then insert at left
    if(i.start < root->start){
        root->left = insertInterval(root->left,i);
    }else{
        root->right = insertInterval(root->right,i);
    }

    //Update ancestor's max if current interval's max is greater
    if(i.end > root->max)
        root->max = i.end;

    return root;
}

bool isOverlapping(Interval i1, Interval i2){

    // if(i1.start < i2.end && i2.start <  i1.end)
    //     return true;
    if (i1.start < i2.end && i2.start < i1.end)
        return true;

    return false;
}

Node *searchOverlapping(Node *root, Interval &i){

    if(!root)
        return NULL;
    
    
    if(isOverlapping(root->i,i))
        return root;

    //If root's left exists and root's left max is greater than low of interval i then search in left subtree
    if(root->left && root->left->max >= i.start)
        return searchOverlapping(root->left,i);

    //Else search in right subtree
        return searchOverlapping(root->right,i);
}

int main(){
    //{1, 5} {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}
    vector<Interval> intervals = {Interval(1,5), Interval(3,7), Interval(2,6), Interval(10,15), Interval(5,6), Interval(4,100)};

    Node *root = new Node(intervals[0]);
    vector<pair<Interval,Interval>> overlappedIntervals;
    for(int i = 1; i<intervals.size();i++){

        if(searchOverlapping(root,intervals[i]))
            overlappedIntervals.push_back({root->i,intervals[i]});

        insertInterval(root,intervals[i]);
    }

    for(auto i : overlappedIntervals)
        cout<<"{ "<<"["<<i.first.start<<", "<<i.first.end<<"] "<<", "<<"["<<i.second.start<<", "<<i.second.end<<"]"<<"}"<<", ";

    return 0;
}