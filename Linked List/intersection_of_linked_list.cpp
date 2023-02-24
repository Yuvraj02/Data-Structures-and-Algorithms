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

int intersectPoint(Node* head1, Node* head2)
{
    Node *d1 = head1,*d2 = head2;

    while (d1!=NULL && d2!=NULL)
    {
        if(d1==d2)
            return d1->data;

        d1 = d1->next;
        d2 = d2->next;

        if(d1==NULL)
            d1 = head2;
        else if(d2==NULL)
            d2 = head1;
    }
    
return -1;
}



int main(){

    Node* head1 = new Node(3);
    Node *tail1 = head1;
    insertAtTail(tail1,6);
    insertAtTail(tail1,9);
    insertAtTail(tail1,15);
    insertAtTail(tail1,30);
    printList(head1);
    //List 2
    Node *head2 = new Node(10);
    Node *tail2 = head2;
    head2->next = head1->next->next->next;
    tail2 = tail1;
    printList(head2);
    cout<<intersectPoint(head1,head2);

    return 0;
}


// int intersectPoint(Node* head1, Node* head2)
// {
//     //Step 1 : Get length
//     int len1 = 0, len2 = 0;
//     Node *l1 = head1, *l2 = head2;
//     while (l1!=NULL)
//     {
//        l1 = l1->next;
//        len1++;
//     }

//     while (l2!=NULL)
//     {
//        l2 = l2->next;
//        len2++;
//     }

//     l1 = head1;
//     l2 = head2;
//     if(len2>len1){
//         l1 = head2;
//         l2 = head1;
//         swap(len1,len2);
//     }
    
//     while (l1!=NULL && l2!=NULL)
//     {
//        // cout<<"s";
//          while (len1!=len2)
//          {
//            // cout<<"s";
//             l1 = l1->next;
//            // cout<<len1<<" ";
//             len1--;
//          }

//          if(l1==l2)
//             return l1->data;
            
//         l1 = l1->next;
//         l2 = l2->next;
//     }
    
//     return -1;
// }