#include <iostream>

using namespace std;

class Node {
    public:

        int data;
        Node *next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail,int val){

    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
}

void printList(Node *head){

    Node *temp = head;

    while (temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

void removeDuplicates(Node* &head){
   
    Node *temp = head;

    while (temp!=NULL)
    {
       if(temp->next!=NULL && temp->data==temp->next->data){
            Node *node_to_delete = temp->next;
            temp->next = temp->next->next;
            delete node_to_delete;
       }else{
        temp = temp->next;
       }
    }
}

int main(){

    Node *head = new Node(1);
    Node *tail = head;

    insertAtTail(tail,2);
    insertAtTail(tail,2);
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    insertAtTail(tail,5);
    insertAtTail(tail,6);
    removeDuplicates(head);
    printList(head);

    return 0;
}