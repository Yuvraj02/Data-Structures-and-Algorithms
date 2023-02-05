#include <iostream>

using namespace std;

class Node{

    public:
        int val;
        Node *nextNode;

    Node(int val){
        this->val = val;
        this->nextNode = NULL;
    }

};

void insertAfter(int data, int val, Node* &tail){

    Node *newNode = new Node(val);
    
    Node *current = tail;

    while (current->val != data)
    {
        current = current->nextNode;
    }
    
    newNode->nextNode = current->nextNode;
    current->nextNode = newNode;
}

void printList(Node* &tail,int position){

    Node *temp = tail;
    
    int index = 1;

    while (index<position)
    {
        cout<<temp->val<<"--->";
        temp = temp->nextNode;
        index++;
    }
    
    cout<<temp->val<<endl;

}

int main(){
    
    Node *tail = new Node(10);
    tail->nextNode = tail;
    insertAfter(10,7,tail);
    printList(tail,3);
    cout<<"Tail: "<<tail->val<<endl;

    return 0;
}