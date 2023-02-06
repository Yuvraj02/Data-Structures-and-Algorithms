#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
        
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtTail(Node* &tail, int val){

    Node *newNode = new Node(val);

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;

}

void reverseDLL(Node* &head)
{   

    Node *previous = NULL;
    Node *current = head;
    Node *forward = current->next;

    while (forward!=NULL)
    {
        current->next = previous;
        current->prev = forward;
        previous = current;
        current = forward;
        forward = forward->next;
    }

    current->next = previous;
    current->prev = forward;
    head = current;
}

void printList(Node* &head){

    Node *temp = head;

    while (temp!=nullptr)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

int main(){

    Node *head = new Node(1);
    Node *tail = head;
    
    for (int i = 2; i < 6; i++)
        insertAtTail(tail,i);

    reverseDLL(head);    
    printList(head);

    return 0;
}