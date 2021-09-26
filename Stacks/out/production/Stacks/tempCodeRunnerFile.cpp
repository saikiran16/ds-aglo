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
    stack<string> st ;
    for(int i = 0 ; i < s.size() ; i++){
        if(!st.empty()){
            st.push(s[i]);
        }
        else{
               int topElement = int(st.top());
               while(topElement > s[i] && k > 0){
                   st.pop();
                   k--
               }
               st.push(s[i]);
        }
    }
    string res = "";
    while(!st.empty()){
        res = res + st.top();
        st.pop();
    }
    reverse(s.begin() , s.end());
    cout << res ;


    return 0;
}