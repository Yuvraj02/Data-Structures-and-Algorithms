#include <iostream>
#include <vector>
using namespace std;

class Node{

    public:
        int data;
        Node *next;
    
    Node(int val){
        this->data = val;
        this->next = NULL;
    }

};

void insertAtTail(Node* &tail, int val){
    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
}

void printList(Node *head){

    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

Node *merge(Node *first, Node* second){

    Node *temp = new Node(-1);
    Node *ans = temp;

    while(first!=NULL && second!=NULL){
        if(first->data < second->data){
            temp->next = first;
            first = first->next;
            temp = temp->next;
        }else{
            temp->next = second;
            second = second->next;
            temp = temp->next;
        }
    }
    if(first) temp->next = first;
    if(second) temp->next = second;

    return ans = ans->next;
}

Node *mergeKLists(vector<Node*>&lists, int i){

    if(i==lists.size()-1)
        return lists[i];

    return merge(lists[i], mergeKLists(lists,i+1));

}

int main(){

    Node *l1 = new Node(1);
    Node *tail1 = l1;
    insertAtTail(tail1,4);
    insertAtTail(tail1,5);
    Node *l2 = new Node(1);
    Node *tail2 = l2;
    insertAtTail(tail2,3);
    insertAtTail(tail2,4);
    Node *l3 = new Node(2);
    Node *tail3 = l3;
    insertAtTail(tail3,6);
    
    vector<Node*> lists = {l1,l2,l3};

    for (int i = 0; i < lists.size(); i++)
    {
        /* code */
        printList(lists[i]);
    }
    Node *sortedLists = mergeKLists(lists, 0);
    printList(sortedLists);
    

    return 0;
}