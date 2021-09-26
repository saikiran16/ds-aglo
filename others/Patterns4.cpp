#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printUpper(int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(j < n-i-1 ) cout << " " ;
            else cout << "*";
        }
        cout << " " ;
        int c = i+1 ;
        for(int j = 0 ; j <= i ; j++){
            cout << c ;c++;
        }

        cout << endl;

    }
    
}
void printLower(int n){
    for(int i = 0 ; i < n ; i++){
        int cc = n;
        for(int j = 0 ; j < n ; j++){
            if(j < n-i-1 ) cout << " " ;
            else 
            {cout << cc ; cc--;}
        }
        cout << " " ;
        int c = i+1 ;
        for(int j = 0 ; j <= i ; j++){
            cout << c ;c++;
        }

        cout << endl;

    }
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n ;
    cin >> n ;
    printLower(n);
    return 0;
}
