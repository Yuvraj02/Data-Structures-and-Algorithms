#include <iostream>

using namespace std;

class Node{
    public:
    int val;
    Node* nextNode;
    Node* previousNode;

    Node(int val){
        this->val = val;
        nextNode=nullptr;
        previousNode=nullptr;
    }
};

void insertAtHead(Node* &head, int val){

    Node *newNode = new Node(val);
    head->previousNode = newNode;
    newNode->nextNode = head;
    head = newNode;

}

void insertAtTail(Node* &tail, int val){

    Node *newNode = new Node(val);

    tail->nextNode = newNode;
    newNode->previousNode = tail;
    tail = newNode;

}

void insertAt(int val,int position, Node* &head, Node* &tail){

    if(position==1){
        insertAtHead(head,val);
        return ;
    }

    Node *temp = head;
    int index = 1;
    while (index<position-1)
    {
        temp = temp->nextNode;
        index++;
    }

    if(temp->nextNode==nullptr){
        insertAtTail(tail,val);
    }else{
        Node *newNode = new Node(val);
        newNode->nextNode = temp->nextNode;
        newNode->previousNode = temp;
        temp->nextNode->previousNode = newNode;
        temp->nextNode = newNode;
    }
}

void printList(Node* &head){

    Node *temp = head;

    while (temp!=nullptr)
    {
        cout<<temp->val<<"-->";
        temp = temp->nextNode;
    }
    cout<<"NULL";
    cout<<endl;
}

void deleteNode(int position, Node* &head, Node* &tail){

    if(position==1){
        Node *temp = head;
        head = head->nextNode;
        head->previousNode = NULL;
        temp->nextNode = NULL;
        delete temp;
        return;
    }

    Node *current = head;
    // Node *prev = NULL;
    int index = 1;
    while (index<position)
    {
        current = current->nextNode;
        index++;   
    }
    
    if(current->nextNode==NULL){
        tail = tail->previousNode;
        tail->nextNode = NULL;
    }else{
        current->previousNode->nextNode = current->nextNode;
        current->nextNode->previousNode = current->previousNode;
       
    }
     current->nextNode = NULL;
     current->previousNode = NULL;
    delete current;
}

int main(){

    Node *head = new Node(20);
    Node *tail = head;
    insertAtHead(head,10);
    printList(head);
    insertAtTail(tail,30);
    printList(head);
    insertAt(15,4,head,tail);
    printList(head);
    deleteNode(4,head,tail);
    printList(head);

    cout<<"Head : "<<head->val<<"\n"<<"Tail : "<<tail->val<<endl;
}