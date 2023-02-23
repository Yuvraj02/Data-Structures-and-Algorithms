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

    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;

    while (current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev=current;
        current=next;
    }
    
    head = prev;

}

Node *addTwoNums(Node* &head1, Node* &head2){

    //Step 1 reverse the lists
    reverse(head1);
    reverse(head2);

    //Add Nums
    Node *first = head1;
    Node *second = head2;
    Node *head3 = new Node(-1);
    Node *tail3 = head3;

    int sum = 0,carry=0,digit=0;
    while (first!=NULL && second!=NULL)
    {
        sum = first->data + second->data + carry;
        digit = sum%10;
        insertAtTail(tail3,digit);
        carry = sum/10;

        first = first->next;
        second = second->next;
    }

    while (first!=NULL)
    {
        sum = first->data+carry;
        digit = sum%10;
       
        insertAtTail(tail3,digit);
        carry = sum/10;
        first = first->next;
    }

    
    while (second!=NULL)
    {
        sum = first->data+carry;
        digit = sum%10;
        
        insertAtTail(tail3,digit);
        carry = sum/10;
        second = second->next;
    }
  
    while (carry!=0)
    {
        sum = carry;
        digit = sum%10;
        insertAtTail(tail3,digit);
        carry = carry/10;
    }
    

    head3 = head3->next;
    reverse(head3);
    return head3;    

}

int main(){

    Node* head1 = new Node(9);
    Node *tail1 = head1;
    insertAtTail(tail1,9);
    Node *head2 = new Node(2);
    Node *tail2 = head2;
    // insertAtTail(tail2,0);
    // insertAtTail(tail2,8);
    //addTwoNums(head1,head2);
    printList(head1);
    printList(head2);
    Node *head3 = addTwoNums(head1,head2);
    printList(head3);
    
    return 0;
}
