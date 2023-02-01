#include <iostream>

using namespace std;


class Node{

    public:
        int val;
        Node *next_node;
        
    //Constructor
    Node(int val){
        this->next_node = nullptr;
        this->val = val;
    }

};

void insertAtHead(Node* &head,int val){
        Node *newNode = new Node(val);
        newNode->next_node = head;
        head = newNode;
}

void insertAtTail(Node* &tail, int val){
    Node *newNode = new Node(val);
    tail->next_node = newNode;
    tail = newNode;
}

void insertAt(Node* &head,Node* &tail,int i, int val){

    if(i==1){
        insertAtHead(head,val);
        return;
    }

    Node *newNode = new Node(val);
    Node *temp = head;
    int index = 1;
    while (index<i-1)
    {
        temp = temp->next_node;
        index++;
    }

    if(temp->next_node==nullptr){
        insertAtTail(tail,val);
    }else{
        newNode->next_node = temp->next_node;
        temp->next_node = newNode;
    }
    
}

void deleteAt(Node* &head, Node* &tail,int position){
        Node *temp = head;

        if(position==1){
            head = head->next_node;
            delete temp;
            return ;
        }

        int index = 1;
        while (index<position-1)
        {
            temp = temp->next_node;
            index++;
        }

        if(temp->next_node->next_node == nullptr){
            
            tail = temp;
            temp = temp->next_node;
            tail->next_node=nullptr;
            delete temp;
            return ;
        }

        Node *nodeToDelete = temp->next_node;
        temp->next_node = nodeToDelete->next_node;

        delete nodeToDelete;
}

void printList(Node* &head){

    Node *temp = head;

    while (temp != nullptr)
    {
        cout<<temp->val<<"->";
        temp = temp->next_node;
    }

    cout<<"NULL";
    
}



int main(){

    Node *head = new Node(10);
    Node *tail = head;
    insertAtTail(tail,20);
    insertAtTail(tail,30);
    insertAtHead(head,5);
    insertAt(head,tail,2,7);
    
    printList(head);

    deleteAt(head,tail,5);
    cout<<endl;
    printList(head);

//    cout<<head->val;

    return 0;
}