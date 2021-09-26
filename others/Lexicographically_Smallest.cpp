#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int getMinIndex(int hash[] , int end){
    int i;
    for (i = end; i>=0 ;i--){
        if(hash[i] != 0){
            
            hash[i]--;
            return i;
        }
    }
        return -1;
}
int main(){
    int hash[26] = {0}, i , threshold , freq = 1;
    char current, prev = -1;
    cout << "Enter the String\n";
    string s , result="";
    cin >> s;
    cout << "Enter threshold\n";
    cin >> threshold;
    for (i = 0; i < s.size(); i++){
        hash[s[i]-'a']++;
    }
        sort(s.begin(), s.end());
    cout << s << endl;
    int mini_index = 25;
    for (i = 0; i < s.size(); i++)
    {
        mini_index = getMinIndex(hash, mini_index);
        if(mini_index == -1) break;
        char current = (char)(mini_index + 'a');
        if(result == ""){
            result = result + current;
        }
        else{
            if(result[i-1] == current){
              //  cout << "Yes Equal "<<endl; freq++;
            }else{
                freq = 1;
            }
            if(freq > threshold){
                hash[mini_index]++;
                freq = 1;
                //cout << "Threshold Limit exceeded Finding Next Largest One : "<< mini_index <<endl;
                int secondMinIndex = getMinIndex(hash, mini_index - 1);
                if(secondMinIndex == -1)
                    break;
                else{
                    char currentSecondChar = (char)(secondMinIndex+ 'a');
                    result = result + currentSecondChar;
                }
            }else{
                    result = result + current;
            }
        }
        //cout << result << " " << freq << " mini_index " << mini_index<< endl;
        /*for (int j = 0; j < 26; j++)
            cout << hash[j] << " "; cout << endl;*/
    }
        return 0;
}