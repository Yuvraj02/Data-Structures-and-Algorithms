#include <iostream>

using namespace std;

void Hello(string name){
    cout<<"Hey "<<name<<" ";
}


void add(int a, int b);
void (*add_num) (int, int);

int main(){

    void (*function_ptr)(string);
    
    function_ptr = Hello;
    function_ptr("Yuvraj");
    add_num = add;
    add_num(4,2);

    return 0;
}

void add(int a, int b){
    cout<<"Your result is: "<<a+b<<endl;
    }