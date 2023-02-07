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

void printList(Node* &tail){

    Node *temp = tail;
    
    do
    {
        cout<<temp->val<<"--->";
        temp = temp->nextNode;
    } while (temp!=tail);
    
    cout<<temp->val<<endl;
}

bool isCircular(Node* head){

    if(head==NULL)
        return true;

    Node *temp = head;

    do {
        temp = temp->nextNode;
        if(temp==head){
            return true;
        }
    }while(temp!=head && temp!=NULL);

    return false;
}

int main(){
    
    Node *tail = new Node(10);
    tail->nextNode = tail;
    insertAfter(10,7,tail);
    insertAfter(7,6,tail);
    insertAfter(6,11,tail);
    insertAfter(10,4,tail);
    printList(tail);
    cout<<"Tail: "<<tail->val<<endl;
    cout<<"List is Circular? : "<<isCircular(tail)<<endl;
    return 0;
}