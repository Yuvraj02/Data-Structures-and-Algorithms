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

void reverse(Node* &head){

    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    //Reverse the lists
    reverse(l1);
    reverse(l2);

    Node *first = l1;
    Node *second = l2;

    Node *temp = new Node(-1);
    Node *ans = temp;

    int borrow = 0,diff = 0;
    while (first!=NULL && second!=NULL)
    {
    
        if(first->data < second->data){
            first->data+=10;
            diff = first->data-second->data-borrow;
            borrow=1;
        }else{
            diff = first->data - second->data-borrow;
            borrow = 0;
        }
    
        insertAtTail(temp,diff);
        first = first->next;
        second = second->next;
    }

    if(first){
        int diff = first->data-borrow;
        insertAtTail(temp,diff);
        borrow=0;
    }

    ans = ans->next;
    reverse(ans);

    while (ans->data == 0)
        ans=ans->next;

    return ans;

}

int main(){

    Node *first = new Node(9);
    Node *tail1 = first;
    insertAtTail(tail1,2);
    insertAtTail(tail1,3);
    Node *second = new Node(9);
    Node *tail2 = second;
    insertAtTail(tail2,9);
    printList(first);
    printList(second);
    Node *result = subLinkedList(first,second);
    printList(result);
    return 0;
}