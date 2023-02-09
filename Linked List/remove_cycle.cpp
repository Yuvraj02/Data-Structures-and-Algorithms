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

Node *detectCycle(Node* &head){

    Node *slow = head,*fast = head;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast)
            return slow;

    }

    return NULL;
}

Node *removeLoop(Node *head)
{
        
        Node *meet = detectCycle(head);

        if(meet==NULL)
            return head;
        
        Node *prev = NULL;
        Node *current = head;
        while (current!=meet)
        {
            prev = meet;
            meet = meet->next;
            current=current->next;
        }
        
        cout<<prev->data<<endl;
        prev->next = NULL;
        //cout<<"Cycle Detected at: "<<current->data<<endl;
return head;
}

int main(){

    Node *head = new Node(1);
    Node *tail = head;
    for (int i = 2; i <= 4; i++)
        insertAtTail(tail,i);

    printList(head);

    //Create a cycle
    head->next->next->next->next = head->next;

    removeLoop(head);
    printList(head);

    return 0;
}