#include <iostream>

using namespace std;

class SpecialStack{
    public:

    SpecialStack *top;
    int val;
    SpecialStack *next;
    int minVal;
    //Default Constructor
    
    SpecialStack(){
      this->top = NULL;
      this->next = NULL;     
    }

    SpecialStack(int data){
        this->val = data;
        this->next = NULL;
        top = this;
    }

    void push(int data){
            SpecialStack *newNode = new SpecialStack(data);
            if(top==NULL){
                top = newNode;
                minVal = top->val;
            }else{
                newNode->next = top;
                top = newNode;
                minVal = min(minVal, top->val);
            }
    }

    int topVal(){
        return top->val;
    }   

    void pop(){
        SpecialStack *node_to_delete = top;
        top = top->next;
        delete node_to_delete;
    }

};


int main(){

    SpecialStack st;
    st.push(2);
    st.push(4);
    st.push(3);
    cout<<st.topVal();


    return 0;
}