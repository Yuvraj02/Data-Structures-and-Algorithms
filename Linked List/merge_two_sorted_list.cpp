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

void merge(Node* &head1, Node* &head2){

    if(head2->data < head1->data){
        merge(head2, head1);
        return ;
    }

    if(head1->next==NULL){
        head1->next = head2;
        return;
    }

    Node *curr1 = head1;
    Node *next1 = curr1->next;
    Node *curr2 = head2;

    while (next1!=NULL && curr2!=NULL)
    {
        if(curr2->data >= curr1->data && curr2->data <= next1->data){
                curr1->next = curr2;
                Node *next2 = curr2->next;
                curr2->next = next1;
                curr1 = curr2;
                curr2 = next2;
        }else{
            curr1 = next1;
            next1 = next1->next;
        }

        if(next1==NULL){
            curr1->next = curr2;
        }

    }
    

}


int main(){

    Node *head1 = new Node(1);
    Node *tail1 = head1;
    Node *head2 = new Node(1);
    Node *tail2 = head2;
    insertAtTail(tail1,2);
    insertAtTail(tail1,3);
    insertAtTail(tail1,4);
    insertAtTail(tail1,5);
    insertAtTail(tail1,5);
    insertAtTail(tail2,3);
    insertAtTail(tail2,4);
    insertAtTail(tail2,6);
    insertAtTail(tail2,7);
    insertAtTail(tail2,8);
    merge(head1,head2);
    printList(head1);
    //printList(head2);
    return 0;
}