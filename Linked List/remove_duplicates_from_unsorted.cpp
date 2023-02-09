#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
    public:

        int data;
        Node *next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail,int val){

    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
}

void printList(Node *head){

    Node *temp = head;

    while (temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

void removeDuplicates(Node* head){

    unordered_set<int> mapp;

    Node *current = head;
    Node *prev = NULL;

    while (current!=NULL)
    {

        if(mapp.find(current->data)!=mapp.end()){
            Node *node_to_delete = current;
            prev->next = current->next;
            current = prev;
            delete node_to_delete;
        }else{
            mapp.insert(current->data);
        }

        prev = current;
        current = current->next;
    }

}
//------Bruteforce Solution----------------
// void removeDuplicates(Node* &head){
   
//     Node *current = head;
//     Node *temp = current;

//     while (current!=NULL)
//     {
//         while (temp!=NULL)
//         {
//             // cout<<"YES";
//             if(temp->next!= NULL && temp->next->data==current->data){
//                 Node *node_to_delete = temp->next;
//                 temp->next = temp->next->next;
//                 delete node_to_delete;    
//             }else{
//                 temp = temp->next;
//             }
//         }
//         current = current->next;
//         temp = current;
//     }
    
// }

int main(){

    Node *head = new Node(1);
    Node *tail = head;

    insertAtTail(tail,4);
    insertAtTail(tail,5);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,2);
    insertAtTail(tail,4);
    insertAtTail(tail,2);
    insertAtTail(tail,4);
    removeDuplicates(head);
    printList(head);

    return 0;
}