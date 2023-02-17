#include <iostream>
#include <unordered_set>
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
    Node *temp = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete temp;
    
}

void removeDuplicates(Node* head){

unordered_set<int> s;

    Node *prev = NULL;
while(head!=NULL){

    if(s.find(head->data) != s.end()){
        Node *node_to_delete = head;
        prev->next = head->next;
        head = prev;
        delete node_to_delete;
    }else{
        s.insert(head->data);
    }

    prev = head;
    head = head->next;
}


}

int main(){

    Node *head = new Node(1);
    Node *tail = head;
    insertAtTail(tail,2);
    insertAtTail(tail,2);
    insertAtTail(tail,4);
    insertAtTail(tail,4);
    removeDuplicates(head);
    printList(head);

    return 0;
}
