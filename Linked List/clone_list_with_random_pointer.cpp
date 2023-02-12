#include <iostream>
#include <unordered_map>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *arb;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->arb = NULL;
    }

};

void insertAtTail(Node* &tail, int data){

    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

Node* insertAtCloneTail(Node* &tail, int data){

    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;

    return newNode;
}

void printList(Node* &head){
    Node *temp = head;

    while (temp!=NULL)
    {
        cout<<temp->data<<"--->";
        temp = temp->next;
    }
    
    cout<<"NULL"<<endl;
}

int main(){

    Node *head = new Node(1);
    Node *tail = head;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);

    printList(head);

    //Create arb pointers
    cout<<"Arb Pointers Of Original :  "<<endl;
    head->arb = head->next->next;
    cout<<head->data<<"--->"<<head->arb->data<<endl;
    head->next->next->arb = tail;
    cout<<head->next->next->data<<"--->"<<head->next->next->arb->data<<endl;
    tail->arb = head->next;
    cout<<tail->data<<"--->"<<tail->arb->data<<endl;
    head->next->arb = head;
    cout<<head->next->data<<"--->"<<head->next->arb->data<<endl;
    //--------------------------

    unordered_map<Node*, Node*> mapp;

    Node *cloneHead = NULL;
    Node *cloneTail = cloneHead;
    Node *temp = head;

    //Create a Clone of original list first
    while (temp!=NULL)
    {
        if(cloneHead==NULL){
            Node *newNode = new Node(temp->data);
            cloneHead = newNode;
            cloneTail=cloneHead;
            mapp.insert(make_pair(temp,newNode));
        }else{
            mapp.insert(make_pair(temp, insertAtCloneTail(cloneTail,temp->data)));
        }

        temp = temp->next;
    }
    
    // auto it = mapp.begin();
    // cout<<"----------------"<<endl;
    // while(it!=mapp.end()){
    //     cout<<it->first->data<<"--->"<<it->second->data<<endl;
    //     it++;
    // }

    //Traverse the list and set arbitrary pointers
    temp = head;
    while(temp!=NULL){
        auto it = mapp.find(temp);
        it->second->arb = temp->arb;

        temp = temp->next;
    }
    cout<<"Clone List: "<<endl;
    printList(cloneHead);
    cout<<"Arb Pointers Of Clone :  "<<endl;
    cout<<head->data<<"--->"<<head->arb->data<<endl;
    cout<<head->next->next->data<<"--->"<<head->next->next->arb->data<<endl;
    cout<<tail->data<<"--->"<<tail->arb->data<<endl;
    cout<<head->next->data<<"--->"<<head->next->arb->data<<endl;
    return 0;
}