#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

void insertAtTail(Node* &tail, int val){

    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
}

Node* kReverse(Node *head,int k){

    if(head==NULL){
        return NULL;
    }

    Node *prev = NULL;
    Node *current = head;
    Node *forward = NULL;
    int i=0;

    while (current!=NULL && i<2)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
        i++;
    }

    if(forward!=NULL){
        head->next = kReverse(forward,k);
    }

    return prev;
}

void printList(Node* &head){

    Node *temp = head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

int main(){

    Node *head = new Node(1);
    Node *tail = head;
    int k = 2;

    for (int i = 2; i <= 6; i++)
        insertAtTail(tail,i);
    printList(head);
    //Node *prev = NULL;
    head = kReverse(head,k);
    printList(head);

    return 0;
}