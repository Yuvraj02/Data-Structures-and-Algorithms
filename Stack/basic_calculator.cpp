  #include<iostream>
  #include <stack>
  #include <utility>

  using namespace std;
  
  void printTop(stack<pair<int,int>> &st){
        if(!st.empty())
            cout<<"( "<<st.top().first<<", "<< st.top().second<<" )"<<endl;
    }

    int calculate(string s) {
        
        long long sum = 0;
       
        int sign = 1;

        stack<pair<int,int>> st;

        for(int i = 0; i<s.size();i++){
            // cout<<"Char is : "<<s[i]<<" Sign is "<<sign<<" --->"<<" ";
            // printTop(st);
            // cout<<"Sum Till Now =  "<<sum<<" ";
            int num = 0;
            if(isdigit(s[i])){
            while(isdigit(s[i]) && i<s.size()){
                num = num*10 + (s[i] - '0');
                i++;
            }
            i--;
            sum+=num*sign;

            sign = 1;
            } else if(s[i] == '('){
                st.push({sum,sign});
                sum = 0;
                sign = 1;
            }else if(s[i] == ')'){
                sum = sum *st.top().second + st.top().first;
                st.pop(); 
            }else if(s[i] == '-'){
                sign = -1;
            }
        }

        // while(!st.empty()){
        //  printTop(st);
        //  st.pop();
        // }
        return sum;
    }