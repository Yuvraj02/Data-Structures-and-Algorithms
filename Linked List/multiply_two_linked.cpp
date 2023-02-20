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


int multiplyLists(Node *first, Node *second){

int num1=0,num2=0;

while(first!=NULL){
    num1 = num1*10 + first->data;
    first = first->next;
}

while (second!=NULL)
{
    num2 = num2*10 + second->data;
    second = second->next;
}

return num1*num2;
}


int main(){

    Node* head1 = new Node(3);
    Node *tail1 = head1;
    Node *head2 = new Node(2);
    Node *tail2 = head2;
    insertAtTail(tail1,2);

    cout<<multiplyLists(head1,head2);    
    return 0;
}