using namespace std ;
#include<bits/stdc++.h>
int main(){
    string s ;
    cout << "Enter a String" <<endl;
    cin >> s ;
    //Create a Hash 
    int hash_arr[26] = {0};
    for(int i = 0 ; i < s.size() ; i++){
        hash_arr[s[i]-'a']++;
    }
    int temp = 0 , i ;
     for( i = 0 ; i < s.size() ; i++){
        if(hash_arr[i] == 1){
            temp  = 1 ;break;
        }
    }
    if(temp == 1)
        cout << "First Unique Character is " << char('a'+i) << endl;
    else
        cout << "There is No Unique Character .All are Repeated Atleast twice." <<endl;

}