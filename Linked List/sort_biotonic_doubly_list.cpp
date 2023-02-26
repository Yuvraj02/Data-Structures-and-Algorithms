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

void reverse(Node* &head){

    Node *previous = NULL;
    Node *current = head;
    Node *next = NULL;

    while(current!=NULL){
        next = current->nextNode;
        current->nextNode = previous;
        previous = current;
        current = next;
    }

    head = previous;
}

void sort(Node* &head){

    //Step 1 Find Mid the node which is smaller
    if(head->nextNode==NULL)
        return;
    Node *second = head->nextNode;
    //Check if it's not a strictly decreasing list
    if(second->val < second->previousNode->val){
        reverse(head);
        return;
    }

    //Strictly increasing case
     while (second->val > second->previousNode->val && second->nextNode!=NULL)
        {
            second = second->nextNode;
        }
    //Step 2 : Divide the lists
    second->previousNode->nextNode = NULL;
    //Reverse the second List
    reverse(second);
    //Step 4: Merge Two sorted Arrays Logic
    Node *first = head;
    Node *dummy = new Node(-1);

    Node *ans = dummy;

    while (first!=NULL && second!=NULL)
    {
        if(first->val < second->val){
            dummy->nextNode = first;
            first->previousNode = dummy;
            first = first->nextNode;
            dummy = dummy->nextNode;
        }else{
            dummy->nextNode = second;
            second->previousNode = dummy;
            second = second->nextNode;
            dummy = dummy->nextNode;
        }
    }
    
    if(first) {
        dummy->nextNode = first;
        first->previousNode = dummy;
    }else{
        dummy->nextNode = second;
        second->previousNode = dummy;
    }
    head = ans->nextNode;
}

int main(){

    Node *head = new Node(20);
    Node *tail = head;
    insertAtTail(tail,17);
    insertAtTail(tail,14);
    insertAtTail(tail,8);
    insertAtTail(tail,3);
    sort(head);
    printList(head);
}