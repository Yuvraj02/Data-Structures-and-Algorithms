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


 Node *zigZag(Node* head)
{
    bool current_is_greater = false;
        
    Node *curr = head;
    
    while(curr!=NULL && curr->next !=NULL){
            
            if(current_is_greater){    
            if(curr->data < curr->next->data){
            
                swap(curr->data, curr->next->data);
            }
            }else {
                if (curr->data > curr->next->data){
                swap(curr->data,curr->next->data);
                }
            }
            curr = curr->next;
            current_is_greater = !current_is_greater;
    }
    return head;
}
int main(){

    Node* head = new Node(1);
    Node *tail = head;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    Node *zig = zigZag(head);
    printList(zig);
    
    return 0;
}

//If you want to swap nodes
// void swapNodes(Node* &previous, Node* &current, Node* &next){
//             Node *temp = next;
//             current->next = temp->next;
//             temp->next = current;
            
//             if(previous!=NULL){
//                 previous->next = temp;
//                 current = previous->next;
//             }             
// }
// Node *zigZag(Node* head)
// {
//         bool current_greater = false;
//         Node *curr = head;
//         Node *prev = NULL;
//         while(curr!=NULL && curr->next!=NULL){
            
//             if(current_greater && curr->data < curr->next->data){
//                     swapNodes(prev,curr,curr->next);
//             }else if (!current_greater && curr->data > curr->next->data){
//                     swapNodes(prev,curr,curr->next);
//             }
            
//             prev = curr;
//             curr = curr->next;
//             current_greater = !current_greater;
//         }
//         return head;
// }