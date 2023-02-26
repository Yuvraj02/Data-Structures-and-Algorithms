#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

    Node(int val){
        this->data = val;
        this->next = nullptr;
    }
};

void insertAtTail(Node* &tail, int val){
    Node *newNode = new Node(val);
    tail->next = newNode;
    tail=newNode;
}

void insertAtHead(Node* &head, int val){
    Node *newNode = new Node(val);
    newNode->next = head;
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

        temp = temp->next;
        index++;
    }
    
    if(temp->next==nullptr){
        insertAtTail(tail,val);
    }else{
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAt(int position, Node* &head, Node* &tail){

    Node *current = head;

    if(position==1){
        head=head->next;
        delete current;
        return ;
    }

    Node *prev = nullptr; 
    int index = 1;

    while (index<position)
    {
        prev = current;
        current = current->next;
        index++;
    }
    
    if(current->next==nullptr){
        //Tail
        tail=prev;
        tail->next=nullptr;
        delete current;
    }else{
        prev->next = current->next;
        delete current;
    }


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

void insertAtDummyTail(Node* &tail, Node *curr){
    tail->next = curr;
    tail = curr;
}

Node* divide(int N, Node *head){
    
    Node *even = new Node(-1);
    Node *evenTail = even;
    Node *odd = new Node(-1);
    Node *oddTail = odd;
    Node *curr = head;
    while(curr!=NULL){
        //Even case
        if(curr->data%2==0){
            insertAtDummyTail(evenTail,curr);
        }else{
            insertAtDummyTail(oddTail,curr);
        }
        curr = curr->next;
    }
    evenTail->next = odd->next;
    oddTail->next = NULL;

    curr = even;
    while(curr->data==-1)
        curr=curr->next;

    return curr;
}

int main(){

    Node* head = new Node(1);
    Node *tail = head;
    insertAtTail(tail,3);
    insertAtTail(tail,5);
    insertAtTail(tail, 7);
    Node *seggregated = divide(2,head);
    printList(seggregated);    
    return 0;
}