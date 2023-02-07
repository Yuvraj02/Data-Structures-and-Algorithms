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

void printList(Node* &head){
    Node *temp = head;

    while (temp!=NULL)
    {   cout<<temp->data<<"--->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void cycleDetection(Node* &head){

    Node *slow = head,*fast = head;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast)
            break;

    }

    if (slow==fast)
    {
        cout<<"Cycle detected!"<<endl;
    
        Node *current = head;
        Node *temp = slow;
        
        while (current!=temp)
        {
            temp = temp->next;
            current=current->next;
        }
        cout<<"Cycle Detected at: "<<current->data<<endl;
    }
}

int main(){

    Node *head = new Node(1);
    Node *tail = head;
    for (int i = 2; i <= 4; i++)
        insertAtTail(tail,i);

    printList(head);

    //Create a cycle
    head->next->next->next->next = head->next;

    cycleDetection(head);
    return 0;
}