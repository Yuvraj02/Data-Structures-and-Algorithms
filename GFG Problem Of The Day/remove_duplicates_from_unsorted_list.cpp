#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_set<int> sett;
    
     Node *curr = head;
     sett.insert(curr->data);
     while(curr!=NULL && curr->next!=NULL){
            
            if(sett.find(curr->next->data) == sett.end()){
                sett.insert(curr->next->data);
                curr = curr->next;
            }else{
                curr->next = curr->next->next;
            }
     }
     
     return head;
    }