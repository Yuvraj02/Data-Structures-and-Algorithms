#include <iostream>

using namespace std;

class Node{
    public:
    int val;
    Node* nextNode;
    Node* previousNode;

    Node(int val){
        this->val = val;
        nextNode=nullptr;
        previousNode=nullptr;
    }
};

void printList(Node* &head){

    Node *temp = head;

    while (temp!=nullptr)
    {
        cout<<temp->val<<"-->";
        temp = temp->nextNode;
    }
    cout<<"NULL";
    cout<<endl;
}

int main(){

    Node *head = new Node(5);
    printList(head);

}