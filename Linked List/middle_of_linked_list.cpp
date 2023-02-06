 #include <iostream>

using namespace std;
 
class Node { 
    public:
        int data;
        Node *next;
        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
};

void insertAtTail(Node* &tail, int val){
    Node *newNode = new Node(val);
    tail->next = newNode;
    tail=newNode;
}

void findMiddle(Node* &head){

    Node *slow = head, *fast=head->next;

    while (fast!=NULL)
    {
        fast = fast->next;
        if(fast != NULL){
        fast = fast->next;
        }
        slow = slow->next;
    }
    
cout<<slow->data;
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

int main(){

    Node *head = new Node(1);
    Node *tail = head;
    
    for (int i = 2; i <= 3; i++)
        insertAtTail(tail,i);

    printList(head);

    findMiddle(head);

    return 0;
}