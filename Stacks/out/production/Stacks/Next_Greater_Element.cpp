//Given an Array of elemets . We have to find next Greater Element for every Array Element.
// 18 7 6 12 15
// o/p : -1 12 12 15 -1
#include<stdio.h>
using namespace std ;
#include<bits/stdc++.h>
void GenerateNextGreaterElements(int arr[] , int n){
    stack<int> st ;
    int result[n];
    memset(result , -1 , sizeof(result));
    st.push(0);
    for(int i = 1 ; i < n ; i++){
        while( !st.empty() && arr[st.top()] < arr[i]){
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i = 0 ; i < n ; i++)
        cout << result[i] << " " ;
}
int main(){
    int arr[] = {18,7,6,12,15};
    int n = 5;
    GenerateNextGreaterElements(arr , n);
    return 0 ;
}