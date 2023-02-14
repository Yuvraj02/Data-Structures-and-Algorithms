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

bool hasCycle(Node *head) {

        if(head==NULL)
            return head;

        Node *slow = head;
        Node *fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                return true;
            }
        }
    return false;
}

int main(){

    Node *head = new Node(1);
    Node *tail = head;
    for (int i = 2; i <= 4; i++)
        insertAtTail(tail,i);
        
    //Create a cycle
    head->next->next->next->next = head->next;

    cout<<hasCycle(head);

    return 0;
}
