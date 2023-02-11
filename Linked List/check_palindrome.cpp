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


Node* reverse(Node* &head){

    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
    
}

bool checkPalindrome(Node* &head){

//Step 1 : Find Middle
Node *slow = head;

Node *fast = head->next;

    while (fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow=slow->next;
    }
    
    Node *prev = NULL;
    Node *temp = slow->next;
    slow->next = reverse(temp);
    Node *first = head;
    Node *second = slow->next;

    while (second!=NULL)
    {
        if (first->data!=second->data)
            return false;
        
        first = first->next;
        second=second->next;
    }
    
return true;
}

int main(){
//4 5 2 5 2 5 4 4 4 1 1
    Node* head = new Node(4);
    Node *tail = head;
    insertAtTail(tail,5);
    insertAtTail(tail,2);
    insertAtTail(tail,5);
    insertAtTail(tail,2);
    insertAtTail(tail,5);
    insertAtTail(tail,4);
    insertAtTail(tail,4);
    insertAtTail(tail,4);
    insertAtTail(tail,1);
    insertAtTail(tail,1);
    cout<<checkPalindrome(head);
    //printList(head);
    
    return 0;
}