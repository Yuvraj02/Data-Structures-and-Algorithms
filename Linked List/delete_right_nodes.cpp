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

void reverse(Node* &head){

    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Node *compute(Node *head)
{

    reverse(head);

    Node *curr = head;
    int maxTillNow = curr->data;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data > curr->next->data){
            curr->next = curr->next->next;
        }else{
            curr = curr->next;
            maxTillNow = curr->data;
        }
    }
    reverse(head);
    return head;
}

int main(){

    Node* head = new Node(10);
    Node *tail = head;
    insertAtTail(tail,20);
    insertAtTail(tail,30);
    insertAtTail(tail,40);
    insertAtTail(tail,50);
    insertAtTail(tail,60);
    Node *removed = compute(head);
    printList(removed);

    return 0;
}

 //Node *compute(Node *head)
// {
//     Node *curr = head;
//     Node *prev = NULL;
//     while (curr!=NULL && curr->next!=NULL){
//         if(curr->next->data > curr->data){
//             Node *node_to_delete = curr->next;
//             curr->data = curr->next->data;
//             curr->next = curr->next->next;
//             delete node_to_delete;
//         }else{
//             curr = curr->next;
//         }
//     }
//     return head;
// }