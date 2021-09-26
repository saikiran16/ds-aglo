#include<iostream>
using namespace std;
void printPatternCol( int n){
    if(n == 0){
        cout <<endl;
        return;
    }
    else {
        cout << "* " ;
        printPatternCol(n - 1);
    }
}
void printPatternRow(int n){
    if(n==0)
        return;
    printPatternCol(n);
    printPatternRow(n - 1);
}
int main(){
    int n;
    cin >> n;
    printPatternRow(n);
    return 0;
}