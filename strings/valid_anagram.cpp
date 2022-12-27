#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

bool isAnagram(string s, string t){

    if(s.size()!=t.size())
        return false;

    map<char,int> a,b;

    for (int i = 0; i < s.size(); i++)
    {
        auto itr1 = a.find(s[i]);
        if(itr1 != a.end())
            itr1->second++;
        else
            a.insert(make_pair(s[i],0));

        itr1 = b.find(t[i]);
        if(itr1 != b.end())
            itr1->second++;
        else
            b.insert(make_pair(t[i],0));
    }
    
    if(a==b)
        return true;
    else
        return false;

}

int main(){

    string s = "adbc",t="abcd";
    cout<<boolalpha<<isAnagram(s,t);

   return 0;
}

//Optimized O(N) Solution (Only works for alphabets)--------
// bool isAnagram(string s, string t){

//     if(s.size()!=t.size())
//         return false;

//     vector<int> a (26,0),b(26,0);

//     for (int i = 0; i < s.size(); i++)
//         a[s[i]-'a']++;

//     for (int i = 0; i < s.size(); i++)
//          b[t[i]-'a']++;

//     for (int i = 0; i < s.size(); i++)
//     {
//         if(a[s[i]-'a']!=b[s[i]-'a']){
//             return false;
//         }
//     }

//     return true;
// }

//Bruteforce O(N Log N)-------
    // sort(s.begin(),s.end());
 