#include <iostream>

using namespace std;

class LinkedList{

    public:
        int data;
        LinkedList* nextNode;

    LinkedList(int data){
        this->data = data;
        this->nextNode = NULL;
    }
};

void insertAtTail(LinkedList* &tail, int val){

    LinkedList *newNode = new LinkedList(val);
    tail->nextNode = newNode;
    tail = newNode;

}

void printList(LinkedList* &head){

    LinkedList *temp = head;

    while (temp!=NULL)
    {
        cout<<temp->data<<"--->";
        temp = temp->nextNode;
    }
    cout<<"NULL"<<endl;
}

void reverse(LinkedList* &head, LinkedList* &prev, LinkedList* &current){

    if(current==NULL){
        head = prev;
        return;
    }
    
    LinkedList *forward = current->nextNode;
    reverse(head, current, forward);
    current->nextNode = prev;
}

void reverseLinkedList(LinkedList* &head){

    LinkedList *prev = NULL;
    LinkedList *current = head;

    reverse(head, prev, current);
}

//Iterative Approach
// void reverseLinkedList(LinkedList* &head){

//     LinkedList *prev = NULL;
//     LinkedList *current = head;
//     LinkedList *next = current->nextNode;

//     while (next!=NULL)
//     {
//         current->nextNode = prev;
//         prev = current;
//         current = next;
//         next = next->nextNode;

//     }
    
//     current->nextNode = prev;
//     head = current;
// }

int main(){

    LinkedList *head = new LinkedList(1);
    LinkedList *tail = head;

    for(int i = 2; i<=6;i++)
        insertAtTail(tail,i);

    reverseLinkedList(head);

    printList(head);
    return 0;
}
