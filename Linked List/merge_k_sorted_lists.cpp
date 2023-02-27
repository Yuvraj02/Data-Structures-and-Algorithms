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


Node *mergeKLists(vector<Node*>&, int);
Node *merge(Node* , Node*);

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

//Time : O(N log K), Space : O(1)

Node* mergeKListsOptimal(vector<Node*>& lists, int start, int end){
    if(start>=end)   
        return lists[start];
    
    int mid = start + (end-start)/2;
    return merge(mergeKListsOptimal(lists,start,mid),mergeKListsOptimal(lists,mid+1,end));
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
        printList(lists[i]);
    }
    Node *sortedLists = mergeKListsOptimal(lists, 0,lists.size()-1);
    printList(sortedLists);
    return 0;
}


//Bruteforce Recursive Solution
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
