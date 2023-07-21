#include <iostream>

struct node {
    
    int data;
    node *next;

    node(int data){
        this->data;
        this->next = NULL;
    }
};


struct node *reverse (struct node *head, int k)
    { 
        if(head==NULL || head->next == NULL)
            return head;
            
        node *curr = head;
        node *prev = NULL;
        node *next = NULL;
        int cnt = 0;
        while(curr !=NULL && cnt<k){
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        
        if(next)
            head->next = reverse(next,k);
            
        return prev;
        
    }