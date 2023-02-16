#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


void insertAtTail(Node* &tail, int val){

    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
}

void printList(Node *head){

    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}


void deleteNode(Node* &node){

    //Copy the contents of next node
    Node *curr = node;
    curr->data = curr->next->data;
    curr->next = curr->next->next;
    
}

int main(){

    Node *head = new Node(1);
    Node *tail = head;
    insertAtTail(tail,2);
    printList(head);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    printList(head);

    //Just for example
    Node *node_to_delete = head->next->next;

    deleteNode(node_to_delete);
    printList(head);
    return 0;
}