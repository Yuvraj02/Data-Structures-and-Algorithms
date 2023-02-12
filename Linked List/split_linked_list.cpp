#include <iostream>

using namespace std;

class Node{

    public:
        int val;
        Node *nextNode;

    Node(int val){
        this->val = val;
        this->nextNode = NULL;
    }

};

void insertAfter(int data, int val, Node* &tail){

    Node *newNode = new Node(val);
    
    Node *current = tail;

    while (current->val != data)
    {
        current = current->nextNode;
    }
    
    newNode->nextNode = current->nextNode;
    current->nextNode = newNode;
}

void printCircularList(Node* &tail){

    Node *temp = tail;
    
    do
    {
        cout<<temp->val<<"--->";
        temp = temp->nextNode;
    } while (temp!=tail);
    
    cout<<temp->val<<endl;
    cout<<"Head : "<<tail->val<<endl;
}

void printList(Node* &head){

    Node *temp = head;
    while (temp!=nullptr)
    {
        cout<<temp->val<<"-->";
        temp = temp->nextNode;
    }
    cout<<"NULL"<<endl;

}

void splitList(Node *head){
    Node *slow = head;
    Node *fast = head->nextNode;
    Node *end = NULL;
   
    while (fast!=head)
    {
        end = fast;
        fast = fast->nextNode;
        
        if(fast!=head){
            end = fast;
            fast = fast->nextNode;
            slow=slow->nextNode;
        }
    }
    
    Node *head2 = slow->nextNode;
    slow->nextNode = NULL;
    end->nextNode = NULL;

    cout<<"After split: "<<endl;

    printList(head);
    printList(head2);

}

int main(){
    
    Node *head = new Node(10);
    head->nextNode = head;
    insertAfter(10,7,head);
    insertAfter(7,6,head);
    insertAfter(6,11,head);
    insertAfter(10,4,head);
    insertAfter(7,9,head);
    printCircularList(head);
    splitList(head);

    return 0;
}