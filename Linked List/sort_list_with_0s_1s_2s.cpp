#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int val){
    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
}

void printList(Node *head){

    while (head!=NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    
    cout<<"NULL"<<endl;
}

void insertAtDummyTail(Node* &tail, Node* &curr){
    tail->next = curr;
    tail = curr;
}

Node* sort(Node *head){

    if(head==NULL || head->next==NULL)
        return head;

    Node *curr = head;
    Node *zeroes = new Node(-1);
    Node *zeroTail = zeroes;
    Node *ones = new Node(-1);
    Node *onesTail = ones;
    Node *twos = new Node(-1);
    Node *twosTail = twos;

    while (curr!=NULL)
    {
        if(curr->data==0)
            insertAtDummyTail(zeroTail, curr);
        else if (curr->data == 1)
            insertAtDummyTail(onesTail,curr);
        else
            insertAtDummyTail(twosTail,curr);

        curr = curr->next;
    }

    zeroTail->next = ones;
    onesTail->next = twos;
    twosTail->next = NULL;

    //Check for NULL Cases
    //Set head first;

    Node *final_head = zeroes;
    while (final_head->data==-1)
        final_head = final_head->next;
    
   //Create links
   curr = final_head;
   Node *prev = NULL;

   while (curr!=NULL)
   {
        if(curr->data==-1){
            Node *node_to_delete = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete node_to_delete;
        }else{
            prev = curr;
            curr=curr->next;
        }
   }

    return final_head;
}

int main(){

    Node *head = new Node(0);
    Node *tail = head;

    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    Node* sorted = sort(head);
    printList(sorted);

    return 0;
}