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

Node *clone(Node* &head);

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

   
   
    cout<<"Clone List: "<<endl;

    Node *cloneHead = clone(head);
    printList(cloneHead);
    cout<<"Arb Pointers Of Clone :  "<<endl;
    cout<<cloneHead->data<<"--->"<<cloneHead->arb->data<<endl;
    cout<<cloneHead->next->next->data<<"--->"<<cloneHead->next->next->arb->data<<endl;
    cout<<tail->data<<"--->"<<tail->arb->data<<endl;
    cout<<cloneHead->next->data<<"--->"<<cloneHead->next->arb->data<<endl;
    return 0;
}

//Optimized Approach
Node *clone(Node* &head){
 Node *cloneHead = NULL;
        Node *cloneTail = cloneHead;
        
        Node *original = head;
        while(original!=NULL){
            
            if(cloneHead==NULL){
                Node *newNode = new Node(original->data);
                cloneHead = newNode;
                cloneTail = cloneHead;
            }else{
                insertAtCloneTail(cloneTail,original->data);
            }
            
            original = original->next;
        }
        
        //Step 2: Add nodes of clone list in between    
        original = head;
        Node *clone = cloneHead;
        
        while(original!=NULL && clone!=NULL){
            Node *next = original->next;
            original->next = clone;
            original = next;
            next = clone->next;
            clone->next = original;
            clone = next;
        }
        
        //Step 3 : Add random pointers
        original = head;
        clone = cloneHead;
        while(original!=NULL){
            original->next->arb = original->arb ? original->arb->next : original->arb;
            original = original->next->next;
        }
        
        //Step 4 revert changes
        original = head;
        clone = cloneHead;
        while(original!=NULL && clone!=NULL){
            original->next = clone->next;
            original = original->next;
            if(original!=NULL){
            clone->next = original->next;
            }
             clone = clone->next;
        }
        
        // printList(head);
        return head;
    }

//Using Map

// Node *clone(Node* &head){

//  unordered_map<Node*, Node*> mapp;

//     Node *cloneHead = NULL;
//     Node *cloneTail = cloneHead;
//     Node *temp = head;

//     //Create a Clone of original list first
//     while (temp!=NULL)
//     {
//         if(cloneHead==NULL){
//             Node *newNode = new Node(temp->data);
//             cloneHead = newNode;
//             cloneTail=cloneHead;
//             mapp.insert(make_pair(temp,newNode));
//         }else{
//             mapp.insert(make_pair(temp, insertAtCloneTail(cloneTail,temp->data)));
//         }

//         temp = temp->next;
//     }
    
//     //Traverse the list and set arbitrary pointers
//     Node *originalNode = head;
//     Node *cloneNode = cloneHead;
//     while(originalNode!=NULL){

//         cloneNode->arb = mapp[originalNode->arb];
//         cloneNode = cloneNode->next;
//         originalNode = originalNode->next;
//     }
//     return cloneHead;
// }