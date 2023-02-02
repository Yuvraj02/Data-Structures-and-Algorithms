#include <iostream>

using namespace std;

class Node {
    public:
        int val;
        Node *nextNode;

    Node(int val){
        this->val = val;
        this->nextNode = nullptr;
    }
};

void insertAtTail(Node* &tail, int val){
    Node *newNode = new Node(val);
    tail->nextNode = newNode;
    tail=newNode;
}

void insertAtHead(Node* &head, int val){
    Node *newNode = new Node(val);
    newNode->nextNode = head;
    head = newNode;
}

void insertAt(int position, int val,Node* &head, Node* &tail){

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
        temp->nextNode = newNode;
    }
}

void deleteAt(int position, Node* &head, Node* &tail){

    Node *current = head;

    if(position==1){
        head=head->nextNode;
        delete current;
        return ;
    }

    Node *prev = nullptr; 
    int index = 1;

    while (index<position)
    {
        prev = current;
        current = current->nextNode;
        index++;
    }
    
    if(current->nextNode==nullptr){
        //Tail
        tail=prev;
        tail->nextNode=nullptr;
        delete current;
    }else{
        prev->nextNode = current->nextNode;
        delete current;
    }


}

void printList(Node* &head){

    Node *temp = head;
    while (temp!=nullptr)
    {
        cout<<temp->val<<"-->";
        temp = temp->nextNode;
    }
    cout<<"NULL"<<endl;

}

int main(){

    Node* head = new Node(10);
    Node *tail = head;
    insertAtTail(tail,20);
    insertAtTail(tail,2);
    insertAtHead(head,5);
    insertAtHead(head,100);
    insertAtTail(tail, 50);
    insertAt(7,200,head,tail);
    printList(head);
    deleteAt(7,head,tail);
    printList(head);
    
    return 0;
}