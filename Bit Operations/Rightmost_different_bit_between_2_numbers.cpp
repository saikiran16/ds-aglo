using namespace std;
#include<bits/stdc++.h>
int main(){
    int num1 , num2;
    cout << "Enter Two Number " << endl;
    cin >> num1 ;
    cin >> num2 ;
    if(num1 == num2) {
        cout << "Numbers are Equal " << endl;
        return 0;
    }
    int counter = 0;
    while(num1%2 == num2%2){
        num1 = num1 >> 1 ;
        num2 = num2 >> 1 ;
        counter++;
    }
    cout << "Ans : " << counter+1 <<endl;
    return 0;
}