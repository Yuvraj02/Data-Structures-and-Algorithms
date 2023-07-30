#include <iostream>

using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
  
   void reverse(ListNode* &head){

        ListNode *curr = head;
        ListNode *next = NULL;
        ListNode *prev = NULL;

        while(curr!=NULL){

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }


    void printList(ListNode *l1){

        while(l1!=NULL){
            cout<<l1->val<<" ";
            l1 = l1->next;
        }
    }

    void insertAtTail(ListNode* &tail, int data){
        ListNode *newNode = new ListNode(data);
        tail->next = newNode;
        tail = newNode;
    }

    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        //1. Step : Reverse
       reverse(first);
       reverse(second);
       // printList(head2);
       //2. Step Create third list with a dummy node
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;

        int sum = 0,carry = 0;
        while(first!=NULL && second!=NULL){
                sum = first->val + second->val + carry; //10
                int digit = sum%10; // 0
                insertAtTail(temp,digit);
                carry = sum/10;
                first = first->next;
                second = second->next;
        }
        
        //If first list is left
        while(first){
            sum = first->val + carry;
            int digit = sum%10;
            insertAtTail(temp,digit);
            carry = sum/10;
            first = first->next;
        }

        //If second list is left
        while(second){
            sum = second->val + carry;
            int digit = sum%10;
            insertAtTail(temp,digit);
            carry = sum/10;
            second = second->next;
        }

        //If carry is left
        while(carry){
            sum = carry;
            int digit = sum%10;
            insertAtTail(temp,digit);
            carry = carry/10;
        }
        reverse(ans->next);

        return ans->next;
    }