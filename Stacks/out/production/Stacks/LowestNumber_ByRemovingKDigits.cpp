#include<stdio.h>
#include<stdlib.h>
using namespace std;
#include<bits/stdc++.h>
int main(){
    string s ;
    cout << "Enter a Number " << endl;
    cin >> s ;   // Reading Number a String
    int k ;
    cout << "Enter No .of Digits to be Removed" ;
    cin >> k;
    stack<char> st ;
    for(int i = 0 ; i < s.size() ; i++){
        cout << "Current Element " << s[i] <<endl;
        if(st.empty()){
            st.push(s[i]);
            cout << "Pushed " << s[i] <<endl;
        }
        else{
               while(!st.empty() && int(st.top()) >= s[i] && k > 0){
                   cout << "Poped " << st.top() <<endl;
                   st.pop();
                   k--;
               }
                cout << "Pushed " << s[i] <<endl;
                st.push(s[i]);
        }
    }
    while(k > 0){        // We may have k > 0 when we have numbers like 123456(Ascending Order). so pop until k is 0.
        st.pop();
        k--;
    }
    string res = "";
    while(!st.empty()){
        res = res + st.top();
        st.pop();
    }
    reverse(res.begin() , res.end());
    
    cout << res ;


    return 0;
}