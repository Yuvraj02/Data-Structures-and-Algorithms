  #include <iostream>
  #include <stack>
  #include <vector>
  using namespace std;

  void reverseString(vector<char>& s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
        }

        for(int i = 0; i < s.size();i++){
            s[i] = st.top();
            st.pop();
        }
    }

int main(){

    vector<char> s = {'y','u','v','r','a','j'};
    reverseString(s);
    for(auto i : s){
        cout<<i;
    }
    return 0;
}
