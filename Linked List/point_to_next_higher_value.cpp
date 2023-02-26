#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *arb;

    Node(int val){
        this->data=val;
        this->next = NULL;
        this->arb = NULL;
    }
};

void insertAtTail(Node* &tail, int val){
    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
}

Node *findMid(Node* head){
    Node *fast = head->next,*slow = head;

    while (fast!=NULL && fast->arb!=NULL)
    {
        slow = slow->arb;
        fast = fast->arb->arb;
    }
    
    return slow;
}

Node *merge(Node *first, Node *second){

    if(first==NULL)
        return second;
    if(second==NULL)
        return first;

    Node *temp = new Node(-1);
    Node *ans = temp;

    while(first!=NULL && second!=NULL){
        if(first->data < second->data){
            temp->arb = first;
            first = first->arb;
            temp = temp->arb;
        }else{
            temp->arb = second;
            second = second->arb;
            temp = temp->arb;
        }
    }
    //For leftover values

    if(first) temp->arb = first;
    if(second) temp->arb = second;
    
    return ans->arb;
}

Node *mergeSort(Node* head){
    if(head==NULL || head->arb==NULL)
        return head;

    //Find mid;
    Node *mid = findMid(head);

    Node *first = head;
    Node *second = mid->arb;
    mid->arb = NULL;

    first = mergeSort(first);
    second = mergeSort(second);

   return merge(first,second);

}

Node *setNext(Node* head){

    Node *curr = head;

    //Set all arb links to next pointer
    while (curr!=NULL)
    {
        curr->arb = curr->next;
        curr = curr->next;
    }
    //Perform mergeSort on arbitrary pointers
    return mergeSort(head);
}

void printList(Node *head){

    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;

}

void printArbPointers(Node *head){

    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head->arb;
    }
    cout<<"NULL"<<endl;

}

int main(){

    Node *head = new Node(5);
    Node *tail = head;
    insertAtTail(tail,10);
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    Node *arbPointersHead = setNext(head);
    printList(head);
    printArbPointers(arbPointersHead);

    return 0;
}