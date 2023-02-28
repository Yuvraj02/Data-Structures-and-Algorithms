#include <iostream>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode(){
            this->val = 0;
            this->next = NULL;
        }

        ListNode(int val){
            this->val = val;
            this->next = NULL;
        }
};

void insertAtTail(ListNode* &tail, int val){
    ListNode *newNode = new ListNode(val);
    tail->next = newNode;
    tail = newNode;
}

void printList(ListNode* head){

    while(head!=NULL){
        cout<<head->val<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode *temp = new ListNode();
    ListNode *ans = temp;

    ListNode *first = l1, *second = l2;
    int carry = 0;
    while (first!=NULL && second!=NULL)
    {
        int sum = first->val+second->val+carry;
        int digit = sum%10;
        insertAtTail(temp,digit);
        carry = sum/10;

        first = first->next;
        second = second->next;
    }

  //For first list
  while(first){
    int sum = first->val + carry;
    int digit = sum%10;
    insertAtTail(temp,digit);
    carry = sum/10;
    first = first->next;
  }  
 //For second List
 while(second){
    int sum = second->val + carry;
    int digit = sum%10;
    insertAtTail(temp,digit);
    carry = sum/10;
    second = second->next;
 }

 //For leftover carry
 while(carry){
    insertAtTail(temp, carry%10);
    carry /= 10;
 }

return ans->next;
}


int main(){
ListNode *num1 = new ListNode(2);
ListNode *num1Tail = num1;
insertAtTail(num1Tail, 4);
insertAtTail(num1Tail, 3);
ListNode *num2 = new ListNode(5);
ListNode *num2TAil = num2;
insertAtTail(num2TAil,6);
insertAtTail(num2TAil,4);

printList(num1);
printList(num2);
ListNode *sum = addTwoNumbers(num1,num2);
printList(sum);
}