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

void insertAtTailOfDummyList(Node* &tail,Node* &temp){

    tail->next = temp;
    tail = temp;
}

void sort(Node* &head){

    Node *zeroListHead = new Node(-1);
    Node *zeroTail = zeroListHead;
    Node *oneListHead = new Node(-1);
    Node *oneTail = oneListHead;
    Node *twoListHead = new Node (-1);
    Node *twoTail = twoListHead;


    Node *temp = head;

    while (temp!=NULL)
    {
        if(temp->data==0){
            insertAtTailOfDummyList(zeroTail,temp);
        }else if(temp->data == 1){
            insertAtTailOfDummyList(oneTail,temp);
        }else{
            insertAtTailOfDummyList(twoTail,temp);
        }

    temp = temp->next;
    }

    //Delete dummy nodes
    zeroListHead = zeroListHead->next;
    oneListHead = oneListHead->next;
    twoListHead = twoListHead->next;


 //Merge these lists
    if(oneListHead == NULL){
        zeroTail->next = twoListHead;
    }else{
        zeroTail->next = oneListHead;
        oneTail->next = twoListHead;
    }
    twoTail->next = NULL;
    head = zeroListHead;
}


//Approach 1
// void sort(Node* &head){

//     int count_0 = 0,count_1=0,count_2=0;

//     Node *temp = head;

//     while (temp!=NULL)
//     {
//         if(temp->val==0)
//             count_0++;
//         else if(temp->val==1)
//             count_1++;
//         else
//             count_2++;

//         temp = temp->next;
//     }
    
//     //Change the existing list value

//     temp = head;
//     //For zeroes
//     while (count_0--)
//     {
//         temp->val = 0;
//         temp = temp->next;
//     }
    
//     //For ones
//     while (count_1--)
//     {
//         temp->val = 1;
//         temp = temp->next;
//     }

//     // //For zeroes
//     while (count_2--)
//     {
//         temp->data = 2;
//         temp = temp->next;
//     }

// }

void printList(Node* &head){

    Node *temp = head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

int main(){

    Node* head = new Node(1);
    Node *tail = head;
    //
    insertAtTail(tail,0);
    insertAtTail(tail,1);
    insertAtTail(tail,1);
    insertAtTail(tail,0);
    insertAtTail(tail,2);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    printList(head);
    sort(head);
    printList(head);
    
    return 0;
}